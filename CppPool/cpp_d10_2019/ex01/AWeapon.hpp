/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon {
	public:
		AWeapon(const std::string &name, int apcost, int damage);
		virtual ~AWeapon();
		std::string const &getName() const {return _name;};
		int getAPCost() const {return _ap;};
		int getDamage() const {return _damage;};
		virtual void attack() const = 0;
	private:
	protected:
		std::string _name;
		int _damage;
		int _ap;
};

#endif /* !AWEAPON_HPP_ */
