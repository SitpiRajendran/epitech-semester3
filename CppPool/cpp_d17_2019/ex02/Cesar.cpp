/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar() : _decal(3)
{
}

void Cesar::encryptChar(char plainchar)
{
    char c;
    if (isalpha(plainchar) == 0) {
        _decal++;
        std::cout << plainchar;
        return;
    }
    if (isupper(plainchar) != 0) {
        c = plainchar + _decal - 'A';
        if (c >= 26)
            c = c % 26;
        c += 'A';
        std::cout << c;
        _decal++;
    } else {
        c = plainchar + _decal - 'a';
        if (c > 26)
            c = c % 26;
        c += 'a';
        std::cout << c;
        _decal++;
    }
}

void Cesar::decryptChar(char cipherchar)
{
    char c;
    if (isalpha(cipherchar) == 0) {
        std::cout << cipherchar;
        _decal++;
        return;
    }
    if (_decal > 26)
        _decal -= 26;
    if (isupper(cipherchar) != 0) {
        c = cipherchar - _decal - 'A';
        while (c < 0)
            c += 26;
        c += 'A';
        std::cout << c;
        _decal++;
    } else {
        c = cipherchar - _decal - 'a';
        while (c < 0)
            c += 26;
        c += 'a';
        std::cout << c;
        _decal++;
    }
}

void Cesar::reset()
{
    _decal = 3;
}