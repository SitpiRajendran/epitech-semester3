/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include <iostream>
#include <cctype>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
	public:
		Cesar();
		virtual ~Cesar() {};
        void encryptChar(char plainchar) override;
        void decryptChar(char cipherchar) override;
        void reset() override;
	protected:
        int _decal;
	private:
};

#endif /* !CESAR_HPP_ */
