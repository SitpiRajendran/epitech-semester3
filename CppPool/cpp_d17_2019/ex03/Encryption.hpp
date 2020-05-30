/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include <iostream>
#include <algorithm>
#include "IEncryptionMethod.hpp"

class Encryption {
    public:
        typedef void(IEncryptionMethod::*theFunction)(char);
        Encryption(IEncryptionMethod &type, theFunction fun) : _type(&type), _func(fun) {};
        ~Encryption() = default;

        void operator()(char);
        static void encryptString(IEncryptionMethod &encryptMethid, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod &encryptMethod, const std::string &toDecrypt);
    protected:
        IEncryptionMethod *_type;
        theFunction _func;
    private:
};

#endif /* !ENCRYPTION_HPP_ */
