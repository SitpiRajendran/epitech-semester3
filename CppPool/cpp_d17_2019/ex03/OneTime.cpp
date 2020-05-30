/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    _key = key;
    for (char &c : _key)
        if (c >= 'A' && c <= 'Z')
		    c = c + 32;
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char c)
{
    if (isalpha(c) == 0) {
        _value++;
        std::cout << c;
        return;
    }
    if (_value >= _key.size())
        _value = _value % _key.size();
    if (isupper(c) != 0) {
        c = c + _key[_value++] - 'A' - 'a';
        if (c >= 26)
            c = c % 26;
        c += 'A';
    } else {
         c = c + _key[_value++] - 'a' - 'a';
        if (c >= 26)
            c = c % 26;
        c += 'a';
    }
    std::cout << c;
}

void OneTime::decryptChar(char c)
{
    if (isalpha(c) == 0) {
        std::cout << c;
        _value++;
        return;
    }
    if (_value >= _key.size())
        _value = _value % _key.size();
    if (isupper(c) != 0) {
        c = c - _key[_value++] - 'A' + 'a';
        while (c < 0)
            c += 26;
        c += 'A';
        std::cout << c;
    } else {
        c = c - _key[_value++] - 'a' + 'a';
        while (c < 0)
            c += 26;
        c += 'a';
        std::cout << c;
    }
}