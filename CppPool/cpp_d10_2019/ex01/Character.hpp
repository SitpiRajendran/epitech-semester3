/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include "AEnemy.hpp"
#include "AWeapon.hpp"

class Character {
	public:
		Character(const std::string &name);
		~Character();
		void recoverAP();
		void equip (AWeapon *weapon) {_weapon = weapon;};
		void attack(AEnemy *enemy);
		AWeapon *getWeapon() const {return _weapon;};
		std::string const &getName() const {return _name;};
		int getAP() const {return _ap;};
	protected:
		std::string _name;
		int _ap;
		AWeapon *_weapon;
	private:
};

std::ostream &operator<<(std::ostream &out, const Character &cara);

#endif /* !CHARACTER_HPP_ */
