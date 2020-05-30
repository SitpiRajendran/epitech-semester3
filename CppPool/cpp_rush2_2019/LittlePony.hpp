/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include <iostream>
#include "Toy.hpp"

class LittlePony : public Toy {
	public:
		LittlePony(const std::string & = "pony");
		~LittlePony();
		void isTaken();
	protected:
	private:
};

#endif /* !LITTLEPONY_HPP_ */
