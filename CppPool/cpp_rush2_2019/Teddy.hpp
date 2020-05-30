/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"
#include <iostream>

class Teddy : public Toy {
	public:
		Teddy(const std::string &);
		~Teddy();
		void isTaken();
	protected:
	private:
};

#endif /* !TEDDY_HPP_ */
