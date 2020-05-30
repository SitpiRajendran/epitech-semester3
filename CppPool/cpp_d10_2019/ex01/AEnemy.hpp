/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>
#include <string>

class AEnemy {
	public:
		AEnemy(int hp, const std::string &type);
		virtual ~AEnemy();

		virtual void takeDamage(int damage);

		std::string const &getType() const {return _type;};
		int getHP() const {return _hp;};

	protected:
		std::string _type;
		int _hp;
	private:
};

#endif /* !AENEMY_HPP_ */
