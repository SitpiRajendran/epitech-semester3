#include "Maper.hpp"

//Constructor & Destructore
indie::Mapper::Mapper(char wall, char brokable, std::vector<char> Players, char bomb, char bonus) {
    this->_wall = wall;
    this->_bombs = bomb;
    this->_bonus = bonus;
    this->_players = Players;
    this->_brokable = brokable;
}
indie::Mapper::~Mapper() {
    this->_Map.clear();
    this->_players.clear();
}

//Set in class the specific chars
void indie::Mapper::setChars(char wall, char brokable, std::vector<char> Players, char bomb, char bonus) {
    this->_wall = wall;
    this->_bombs = bomb;
    this->_bonus = bonus;
    this->_players = Players;
    this->_brokable = brokable;
}

//Set a char at position, & remove a player if it's that char which is set
void indie::Mapper::setCharPos(char c, size_t x, size_t y, bool force) {
    size_t k = 0;
    size_t l = 0;
    bool isPlayer = false;

    if (x > 22 || y > 22 || this->_Map[x][y] == '1' || this->_Map[x][y] == '2')
        return;
    if (c != this->_wall && c != this->_bonus && c != this->_bombs && c != this->_brokable)
        for (size_t i = 0; i < this->_players.size(); i ++)
            if (c == this->_players[i])
                isPlayer = true;
    else
        isPlayer = true;
    for (size_t i = 0; isPlayer && i < this->_players.size(); i ++) {
        if (c == this->_players[i]) {
            for (; k < this->_Map.size() - 1 && this->_Map[k].find(c) == std::string::npos; k ++);
            for (; l < this->_Map[k].length() - 1 && this->_Map[k][l] != c; l ++);
            if (this->_Map[k][l] == c)
                this->_Map[k][l] = ' ';
        }
    } if (force)
        this->_Map[x][y] = c;
    else if (!force && this->_Map[x][y] == ' ')
        this->_Map[x][y] = c;
}

//Check and reset the players
void indie::Mapper::check_map(std::vector<MyPerso *> players) {
    for (size_t i = 0; i < players.size(); i ++) {
        this->setCharPos(this->getPlayers()[i], players[i]->getNode()->getPosition().X / 3, players[i]->getNode()->getPosition().Z / 3);
    }
}

void indie::Mapper::setMap(std::vector<std::string> Map) {
    this->_Map.clear();
    this->_Map = Map;
}

void indie::Mapper::setWall(char wall) {this->_wall = wall;}
char indie::Mapper::getWall(void) const {return this->_wall;}
char indie::Mapper::getBonus(void) const {return this->_bonus;}
char indie::Mapper::getBombs(void) const {return this->_bombs;}
void indie::Mapper::setBonus(char bonus) {this->_bonus = bonus;}
void indie::Mapper::setBombs(char bombs) {this->_bombs = bombs;}
char indie::Mapper::getBrokable(void) const {return this->_brokable;}
void indie::Mapper::setBrokable(char brokable) {this->_brokable = brokable;}
std::vector<std::string> indie::Mapper::getMap(void) const {return this->_Map;}
std::vector<char> indie::Mapper::getPlayers(void) const {return this->_players;}