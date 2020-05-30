/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist(const std::string &name = "Power Fist", int apcost = 8, int damage = 50);
		~PowerFist();
		void attack() const;
	protected:
	private:
};

#endif /* !PowerFist_HPP_ */
