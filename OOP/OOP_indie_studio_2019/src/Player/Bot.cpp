/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bot
*/

#include "Bot.hpp"

//Constructor Destructor
indie::Bot::Bot() {
    _posX = 1;
    _posY = 1;
    _num = '2';
    _destX = 10;
    _destY = 10;
    lastdir = 'N';
    _lost = false;
    _action = ATTACK;
}
indie::Bot::~Bot()
{
}

//Find Bombs in the map and set dangerous places
std::vector<std::string> indie::Bot::map_bomb(std::vector<std::string> map, int x, int y)
{
    int aa = 0;
    printf("J'ai VU UNE BOMBE! <3\n");
    for (size_t i = 0; i < 3 && map[x + i][y] != '#' && map[x + i][y] != '1'; i ++) {
        if (map[x + i][y] == '2')
            aa = 1;
        else if (map[x+i][y] == 'Q')
            continue;
        else
            map[x + i][y] = 'D';
    } for (size_t i = 0; i < 3 && map[x - i][y] != '#' && map[x - i][y] != '1'; i ++) {
        if (map[x - i][y] == '2')
            aa = 1;
        else if (map[x-i][y] == 'Q')
            continue;
        else
            map[x - i][y] = 'D';
    } for (size_t i = 0; i < 3 && map[x][y + i] != '#' && map[x][y + i] != '1'; i ++) {
        if (map[x][y + i] == '2')
            aa = 1;
        else if (map[x][y+i] == 'Q')
            continue;
        else
            map[x][y + i] = 'D';
    } for (size_t i = 0; i < 3 && map[x][y - i] != '#' && map[x][y - i] != '1'; i ++) {
        if (map[x][y - i] == '2')
            aa = 1;
        else if (map[x][y-i] == 'Q')
            continue;
        else
            map[x][y - i] = 'D';
    } if (aa == 0) {
        _action = ATTACK;
        _lost = 1;
    } else if (aa == 1)
        _action = DEFENSE;

    return map;
}

// modify the map adding dangerous places
std::vector<std::string> indie::Bot::map_modifier(std::vector<std::string> &map)
{
    for (size_t x = 0; x < map.size() - 1; x ++)
        for (size_t y = 0; y < map[x].length() - 1; y ++)
            if (map[x][y] == 'Q')
                map = map_bomb(map, x, y);
    return map;
}

//Put a T on the Map to dodge the Bomb
void indie::Bot::new_dest_defense(std::vector<std::string> &map)
{
    int Tx = 1;
    int Ty = 1;

    std::vector<std::string> tmp = map;
    PathFinder().findPosByChar(tmp, 'T', Tx, Ty);

    if (Tx == 1 && Ty == 1) {
        // PathFinder().setMap(tmp);
        _destX = 0;
        _destY = 0;
        for (size_t x = 0; x + _posX < map.size() - 1 && _destY == 0; x++) {
            for (size_t y = 0; y + _posY < map[x].length() - 1 && map[x + _posX][y + _posY] != 'Q'; y++) {
                if (map[x + _posX][y + _posY] == ' ') {
                    _destX = x + _posX;
                    _destY = y + _posY;
                    break;
                }
            }
        } for (size_t x = 0; x + _posX < map.size() - 1 && _destY == 0; x++) {
            for (size_t y = 0; _posY - y > 0 && map[x + _posX][_posY - y] != 'Q'; y++) {
                if (map[x + _posX][_posY - y] == ' ') {
                    _destX = x + _posX;
                    _destY = _posY - y;
                    break;
                }
            }
        } for (size_t x = 0; _posX - x > 0 && _destY == 0; x++) {
            for (size_t y = 0; y + _posY < map[x].length() - 1 && map[_posX - x][y + _posY] != 'Q'; y++) {
                if (map[_posX - x][y + _posY] == ' ') {
                    _destX = _posX - x;
                    _destY = y + _posY;
                    break;
                }
            }
        } for (size_t x = 0; _posX - x > 0 && _destY == 0; x++) {
            for (size_t y = 0; _posY - y > 0 && map[_posX - x][_posY - y] != 'Q'; y++) {
                if (map[_posX - x][_posY - y] == ' ') {
                    _destX = _posX - x;
                    _destY = _posY - y;
                    break;
                }
            }
        }
        map[_destX][_destY] = 'T';
    }
    PathFinder().findPosByChar(map, 'T', Tx, Ty);
    map[_posX][_posY] = '2';
    tmp = PathFinder().myway(map, 'T', '2');
    PathFinder().printMap(tmp);
    map[_posX][_posY] = ' ';
    tmp[_posX][_posY] = ' ';
    if (tmp[_posX + 1][_posY] == 'o' || tmp[_posX + 1][_posY] == 'T' || tmp[_posX + 1][_posY] == 'D') {
        map[_posX+1][_posY] = _num;
        _posX +=1;
    } else if (tmp[_posX][_posY + 1] == 'o'|| tmp[_posX][_posY + 1] == 'T' || tmp[_posX][_posY + 1] == 'D') {
        map[_posX][_posY+1] = _num;
        _posY += 1;
    } else if (tmp[_posX - 1][_posY] == 'o' || tmp[_posX - 1][_posY] == 'T' || tmp[_posX - 1][_posY] == 'D') {
        map[_posX-1][_posY] = _num;
        _posX -=1;
    } else if (tmp[_posX][_posY - 1] == 'o' || tmp[_posX][_posY - 1] == 'T' || tmp[_posX][_posY - 1] == 'D') {
        map[_posX][_posY-1] = _num;
        _posY -= 1;
    } else {
        printf("NO GPS FOUND\n");
        _lost = 1;
        _action = ATTACK;
        map[_posX][_posY] = _num;
    }
    tmp.clear();
}

// Choose a new destination to attack
void indie::Bot::new_dest_attack(std::vector<std::string> &map) {
    std::vector<std::string> tmp = map;
    PathFinder().printMap(tmp);
    _posX = 1;
    _posY = 1;
    PathFinder().findPosByChar(map, '2', _posX, _posY);
    printf("POSITION NewDest Before : %d - %d\n", _posX, _posY);
    map[_posX][_posY] = ' ';
    if (tmp[_posX + 1][_posY] == 'o' || tmp[_posX + 1][_posY] == 'T' || tmp[_posX + 1][_posY] == 'D' || tmp[_posX + 1][_posY] == '2') {
        map[_posX+1][_posY] = _num;
        _posX += 1;
    } else if (tmp[_posX][_posY + 1] == 'o'|| tmp[_posX][_posY + 1] == 'T' || tmp[_posX][_posY + 1] == 'D' || tmp[_posX][_posY + 1] == '2') {
        map[_posX][_posY+1] = _num;
        _posY += 1;
    } else if (tmp[_posX - 1][_posY] == 'o' || tmp[_posX - 1][_posY] == 'T' || tmp[_posX - 1][_posY] == 'D' || tmp[_posX - 1][_posY] == '2') {
        map[_posX -1][_posY] = _num;
        _posX -= 1;
    } else if (tmp[_posX][_posY - 1] == 'o' || tmp[_posX][_posY - 1] == 'T' || tmp[_posX][_posY - 1] == 'D' || tmp[_posX][_posY - 1] == '2') {
        map[_posX][_posY - 1] = _num;
        _posY -= 1;
    } else {
        printf("NO GPS FOUND\n");
        _lost = 1;
        PathFinder().setMap(tmp);
        _action = DEFENSE;
        map[_posX][_posY] = _num;
    }
    printf("POSITION NewDest After : %d - %d\n", _posX, _posY);
    tmp.clear();
}

//Launch the Bot play move
void indie::Bot::activate(std::vector<std::string> &map) {

    std::vector<std::string> tmp = map;
    int x = 1;
    int y = 1;
    map_modifier(tmp);
    printf("POSITION : %d - %d\nAction : %d\n", _posX, _posY, _action);
    PathFinder().printMap(tmp);
    if (_action == DEFENSE)
        new_dest_defense(tmp);
    else if (_action == ATTACK) {
        if (_lost && PathFinder().pathFinding(tmp)) {
            _lost = false;
            _destY == 0;
            tmp = PathFinder().myway(tmp, '1', '2');
            new_dest_attack(tmp);
        } else
            new_dest_attack(tmp);
    }
    PathFinder().findPosByChar(map, '2', x, y);
    map[x][y] = ' ';
    map[_posX][_posY] = '2';
    PathFinder().printMap(map);
    printf("POSITION AFTER: %d - %d\n", _posX, _posY);
}

//Update all the position we need for the player
void indie::Bot::getAllPosition(MyPerso &player, int &x, int &y) {
    _posX = (int)player.getNode()->getPosition().X / 3;
    _posY = (int)player.getNode()->getPosition().Z / 3;
    x = _posX;
    y = _posY;
}

//Litteraly does the Movement and set the result of the next
void indie::Bot::Movement(int &x, int &y, MyPerso &player) {
    bool moving = false;

    printf("I have to go %s\n", lastdir == 'U' ? "Up" : (lastdir == 'D' ? "Down" : (lastdir == 'R' ? "Right" : lastdir == 'L' ? "Left" : (lastdir == 'N' ? "Je dois attendre" : "where the wind drive me"))));
    switch (lastdir) {
        case 'U': player.getCharacter()->animUp(); break;
        case 'D': player.getCharacter()->animDown(); break;
        case 'R': player.getCharacter()->animRight(); break;
        case 'L': player.getCharacter()->animLeft(); break;
        default: break;
    } if (x < _posX) {
        lastdir = 'U';
        moving = true;
    } else if (x > _posX) {
        lastdir = 'D';
        moving = true;
    } else if (y < _posY) {
        lastdir = 'R';
        moving = true;
    } else if (y > _posY) {
        lastdir = 'L';
        moving = true;
    } if (!moving)
        player.getCharacter()->reInitAnim();
}

//Use that function if a brokable wall is blocking the AI
void indie::Bot::breakable_function(MyPerso &player, Mapper &Asciimap, EventParticular &evt, int &x, int &y) {
    if (Asciimap.getMap()[x][y] == 'C') {
        player.getCharacter()->bombPos();
        evt = BombPosP2;
        switch (lastdir) {
            case 'U': player.getCharacter()->animUp();    x --; break;
            case 'D': player.getCharacter()->animDown();  x ++; break;
            case 'R': player.getCharacter()->animRight(); y ++; break;
            case 'L': player.getCharacter()->animLeft();  y --; break;
            default: break;
        }
        Asciimap.setCharPos('Q', (int)player.getNode()->getPosition().X / 3, (int)player.getNode()->getPosition().Z / 3, true);
    }
}


//The main movement function
void indie::Bot::updatePlayer(MyPerso &player, std::vector<std::string> map, Mapper &Asciimap, EventParticular &evt) {
    int x = 1;
    int y = 1;
    std::vector<std::string> tmp = map;

    getAllPosition(player, x, y);
    this->activate(tmp);

    Asciimap.setMap(tmp);
    PathFinder().findPosByChar(tmp, '2', _posX, _posY);

    this->Movement(x, y, player);
    this->breakable_function(player, Asciimap, evt, x, y);
    tmp.clear();
}

