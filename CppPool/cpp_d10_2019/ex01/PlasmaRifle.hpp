/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle(const std::string &name = "Plasma Rifle", int apcost = 5, int damage = 21);
		~PlasmaRifle();
		void attack() const;
	protected:
	private:
};

#endif /* !PLASMARIFLE_HPP_ */
