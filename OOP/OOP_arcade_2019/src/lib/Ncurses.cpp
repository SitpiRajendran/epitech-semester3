/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

extern "C" arcade::IDisplay *entryPoint()
{
    return new lib::Ncurses();
}

extern "C" void destroy(arcade::IDisplay *lib)
{
    delete lib;
}

bool alphabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

namespace lib
{
Ncurses::Ncurses()
{
    initscr();
    getmaxyx(stdscr, this->_height, this->_length);
    clear();
    refresh();
    curs_set(0);
    noecho();
    nodelay(stdscr, true);
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::Refresh()
{
    refresh();
}

void Ncurses::Clear()
{
    clear();
}

void Ncurses::dispMap(std::vector<std::string> &map, arcade::Element &map_element)
{
    //todo
}

void Ncurses::dispObject(std::vector<arcade::Element> &allElement)
{
/*     std::vector<arcade::Element>::iterator it;
    for (it = allElement.begin(); it < allElement.end(); it++) {
        mvprintw(it->getPosition().getPositionX(), it->getPosition().getPositionY(), it->getElement().c_str());
    } */
}

int Ncurses::menu(std::vector<std::string> &gameLib_path)
{
    int choice = 0; 
    int highlight = 0;
    int highlightLib = 0;
    int offset;

    std::vector<std::string>::iterator it = gameLib_path.begin();
    std::string dispLib[3] = {"SFML", "Ncurses", "SDL"};
    char a;

    WINDOW *gameWindow = newwin(10, this->_length - 12, 1, 5); //6 hauteur, 12 longueur, 8 position y, 5 position x
    WINDOW *graphWindow = newwin(10, this->_length - 12, (this->_height / 2) - 5, 5);
    WINDOW *nameWindow = newwin(10, this->_length - 12, this->_height - 11, 5);
    box(gameWindow, 0, 0);
    box(graphWindow, 0, 0);
    box(nameWindow, 0, 0);
    Refresh();
    wrefresh(gameWindow);
    wrefresh(graphWindow);
    wrefresh(nameWindow);
    keypad(gameWindow, true);
    while (1)
    {
        if (currentWindow == 0)
        {
            offset = getmaxx(gameWindow) / 4;
            for (int i = 0; i < gameLib_path.size(); i++)
            {
                wattron(gameWindow, A_BOLD);
                mvwprintw(gameWindow, 2, (getmaxx(gameWindow) / 2) - 5, "SELECT GAME");
                wattroff(gameWindow, A_BOLD);
                if (i == highlight)
                    wattron(gameWindow, A_REVERSE);
                mvwprintw(gameWindow, 6, offset - (gameLib_path.at(i).size() / 2), gameLib_path.at(i).c_str());
                wattroff(gameWindow, A_REVERSE);
                offset *= 3;
            }
            choice = wgetch(gameWindow);
            switch (choice)
            {
            case KEY_LEFT:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                break;
            case KEY_RIGHT:
                highlight++;
                if (highlight == 2)
                    highlight = 1;
                break;
            case '*':
                return (arcade::QUIT);
            default:
                break;
            }
            if (choice == 10)
            {
                keypad(gameWindow, false);
                currentWindow = 1;
            }
        }

        if (currentWindow == 1)
        {
            keypad(graphWindow, true);

            offset = getmaxx(graphWindow) / 4;
            int saveOffset = offset;
            for (int i = 0; i < 3; i++)
            {
                wattron(graphWindow, A_BOLD);
                mvwprintw(graphWindow, 2, (getmaxx(graphWindow) / 2) - 5, "SELECT LIB");
                wattroff(graphWindow, A_BOLD);
                if (i == highlightLib)
                    wattron(graphWindow, A_REVERSE);
                mvwprintw(graphWindow, 6, offset - (dispLib[i].size() / 2), dispLib[i].c_str());
                wattroff(graphWindow, A_REVERSE);
                offset += saveOffset;
            }
            choice = wgetch(graphWindow);
            switch (choice)
            {
            case KEY_UP:
                currentWindow = 0;
                highlight = 0;
                keypad(gameWindow, true);
            case KEY_LEFT:
                highlightLib--;
                if (highlightLib == -1)
                    highlightLib = 0;
                break;
            case KEY_RIGHT:
                highlightLib++;
                if (highlightLib == 3)
                    highlightLib = 2;
                break;
            case '*':
                return (arcade::QUIT);
            default:
                break;
            }
            if (choice == 10)
            {
                keypad(graphWindow, false);
                currentWindow = 2;
                if (highlightLib == 0)
                    return(arcade::PREV_LIB);
                if (highlightLib == 2)
                    return(arcade::NEXT_LIB);
            }
        }

        if (currentWindow == 2)
        {
            keypad(nameWindow, true);
            mvwprintw(nameWindow, 2, (getmaxx(nameWindow) / 2) - 4, "SET NAME");
            mvwprintw(nameWindow, 5, (getmaxx(nameWindow) / 2)-(_name.size()/2), _name.c_str());
            a = wgetch(nameWindow);
            if (a == KEY_UP)
                currentWindow = 1;
                highlightLib = 0;
                keypad(graphWindow, true);
            if (alphabet(a))
                _name += a;
            if (a == '*')
                return (arcade::QUIT);
            if (a == 10) {
                keypad(nameWindow, false);
                break;
            }
        }
    }
    return (11);
}

int Ncurses::getEvent()
{
    return (getch());
}

std::string Ncurses::getName()
{
    return _name;
}

void Ncurses::setName(const std::string &name)
{
    _name = name;
}

int Ncurses::getTimeDiff()
{
    return (0);
}

void Ncurses::dispName(std::string name)
{
}

void Ncurses::dispScore(int score)
{
}

} // namespace lib
