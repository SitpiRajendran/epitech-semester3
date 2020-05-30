/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <iostream>

#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
	public:
		OneTime(const std::string &key);
		~OneTime();

		void encryptChar(char) override;
		void decryptChar(char) override;
		void reset() override {_value = 0;};
	protected:
		std::string _key;
		size_t _value;
	private:
};

#endif /* !ONETIME_HPP_ */
