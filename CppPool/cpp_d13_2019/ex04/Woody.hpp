/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"
#include "Picture.hpp"

class Woody : public Toy {
	public:
		Woody(std::string name, std::string ascii = "woody.txt");
		~Woody();
		void speak(std::string str);
	protected:
	private:
};

#endif /* !WOODY_HPP_ */
