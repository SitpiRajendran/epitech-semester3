/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :
    m_serial(serial), _x(x), _y(y), _next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *temp = new KreogCom(x, y , serial);

    temp->_next = _next;
    _next = temp;
}

void KreogCom::removeCom()
{
    KreogCom *to_delete;

    if (_next == NULL)
        return;
    to_delete = _next;
    _next = _next->_next;
    delete to_delete;
}

KreogCom *KreogCom::getCom()
{
    return (_next);
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " ";
    std::cout << _y << std::endl;
}

void KreogCom::locateSquad()
{
    KreogCom *temp;

    if (_next != NULL) {
        temp = _next;
        temp->ping();
        while (temp->_next != NULL) {
            temp = temp->_next;
            temp->ping();
        }
    ping();
    }
}