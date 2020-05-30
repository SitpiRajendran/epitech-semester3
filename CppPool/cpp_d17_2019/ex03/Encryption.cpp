/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Encryption
*/

#include "Encryption.hpp"

void Encryption::operator()(char car)
{
    (_type->*_func)(car);
}

void Encryption::encryptString(IEncryptionMethod &encryptMethod, const std::string &toEncrypt)
{
    encryptMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &encryptMethod, const std::string &toDecrypt)
{
    encryptMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}