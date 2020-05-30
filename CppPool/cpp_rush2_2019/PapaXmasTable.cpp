/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    for (int i = 0; i < 10; i += 1)
        _array[i] = NULL;
}

PapaXmasTable::~PapaXmasTable()
{
}

int PapaXmasTable::last_place()
{
    int i = 0;

    for (; _array[i]; i++);
    return i;
}

void PapaXmasTable::free_table()
{
    for (int i = 0; i < 10; i += 1)
        _array[i] = NULL;
}

void PapaXmasTable::putTable(Object *objet) {
    if (!objet) {
        std::cerr << "[putTable][Table.cpp]: Null *Object \"objet\" :/" << std::endl;
        exit(84);
    } if (last_place() == 10) {
        std::cout << "Table Collapse (More than 10 Objects) :(" << std::endl;
        free_table();
    } else
        _array[last_place()] = objet;
}

Object *PapaXmasTable::takeTable()
{
    Object *temp;
    int last = last_place() - 1;

    if (last == -1) {
        std::cerr << "[takeTable][Table.cpp]: No Object to take (°~°)" << std::endl;
        return NULL;
    }
    temp = _array[last];
    _array[last] = NULL;

    return temp;
}
Object *PapaXmasTable::takeTable(int pos)
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

std::string *PapaXmasTable::lookTable()
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

ITable *PapaXmasTable::createTable()
{
    ITable *itable = new PapaXmasTable;
    return (itable);
}

int PapaXmasTable::isToy() const
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

int PapaXmasTable::isBox() const
{
    int len = 0;

    for(; len < 10; len += 1)
        if (_array[len] != NULL && _array[len]->getID() == 3)
            return len;
    return -1;
}

int PapaXmasTable::isPaper() const
{
    int len = 0;

    for(; len < 10; len += 1)
        if (_array[len] != NULL && _array[len]->getID() == 4)
            return len;
    return -1;
}