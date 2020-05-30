/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** SuperMutant
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include <iostream>
#include <string>
#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
	public:
		SuperMutant();
		~SuperMutant();
		void takeDamage(int damage);
	protected:
	private:
};

#endif /* !SUPERMUTANT_HPP_ */
