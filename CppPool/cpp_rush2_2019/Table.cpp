/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Table
*/

#include "Table.hpp"
#include <string>
#include <iostream>

Table::Table()
{
    for (int i = 0; i < 10; i += 1)
        _array[i] = NULL;
}

Table::~Table()
{
}

int Table::last_place()
{
    int i = 0;

    for (; _array[i] != NULL; i+= 1);
    return i;
}

void Table::free_table()
{
    for (int i = 0; i < 10; i ++)
        _array[i] = NULL;
}

void Table::putTable(Object *objet) {
    if (!objet) {
        std::cerr << "[putTable][Table.cpp]: Null *Object \"objet\" :/" << std::endl;
        exit(84);
    } if (last_place() >= 10) {
        std::cout << "Table Collapse (More than 10 Objects) :(" << std::endl;
        free_table();
    } else
        _array[last_place()] = objet;
}

Object *Table::takeTable()
{
    Object *temp;
    int last = last_place() - 1;

    if (last == 10) {
        std::cerr << "[takeTable][Table.cpp]: No Object to take (°~°)" << std::endl;
        return NULL;
    }
    temp = _array[last];
    _array[last] = NULL;

    return temp;
}
Object *Table::takeTable(int pos)
{
    Object *temp;
    if (pos < 0 || pos > 9) {
        std::cerr << "[takeTable][Table.cpp]: No Object to take (°~°)" << std::endl;
        exit(84);
    }
    temp = _array[pos];
    _array[pos] = NULL;

    return temp;
}

std::string *Table::lookTable(void)
{
    int len = 0;
    int indexe = 0;
    std::string *title_array = new std::string[10];

    std::cout << "--------- Sur ma Table ---------" << std::endl;
    for(; len < 10; len += 1)
        if (_array[len] != NULL) {
            std::cout <<  len << " : " << _array[len]->getTitle() << std::endl;
            title_array[indexe] = _array[len]->getTitle();
            indexe ++;
        }
    std::cout << "--------------------------------" << std::endl;
    return (title_array);
}

ITable *Table::createTable(void)
{
    ITable *itable = new Table;
    return (itable);
}

int Table::isToy() const
{
    int len = 0;

    for(; len < 10; len += 1) {
        if (_array[len] != NULL && _array[len]->getID() == 1)
            return len;
        if (_array[len] != NULL && _array[len]->getID() == 2)
            return len;
    }
    return -1;
}

int Table::isBox() const
{
    int len = 0;

    for(; len < 10; len += 1)
        if (_array[len] != NULL && _array[len]->getID() == 3)
            return len;
    return -1;
}

int Table::isPaper() const
{
    int len = 0;

    for(; len < 10; len += 1)
        if (_array[len] != NULL && _array[len]->getID() == 4)
            return len;
    return -1;
}