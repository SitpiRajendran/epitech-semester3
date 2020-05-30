/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"
#include <iostream>

class ToyStory {
	public:
		ToyStory();
		~ToyStory();
        static void tellMeAStory(std::string filename, Toy &t1, bool (Toy::*func1)(std::string const), Toy &t2, bool (Toy::*func2)(std::string const));
	protected:
        std::string _filename;
	private:
};

#endif /* !TOYSTORY_HPP_ */
