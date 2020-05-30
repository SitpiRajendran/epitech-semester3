/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Object.hpp"

class Toy : public Object {
	public:
		Toy(const std::string &);
		~Toy();
		Object *getObject(void) const {return NULL;};
	protected:
	private:
};

#endif /* !TOY_HPP_ */
