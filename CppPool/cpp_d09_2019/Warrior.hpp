/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public Character
{
	public:
		Warrior(const std::string &name, int level, std::string weapon = "hammer");
		~Warrior();

		int CloseAttack();
		int RangeAttack();
	protected:
	private:
		std::string weaponName;
};

#endif /* !WARRIOR_HPP_ */
