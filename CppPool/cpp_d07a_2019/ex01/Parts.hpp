/*
** EPITECH PROJECT, 2020
** CppPool - D07a

** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Arms {
	private:
		std::string _serial = "A-01";
		bool _functional = true;
	public:
		Arms(std::string serial = "A-01", bool functional = true);
		~Arms();
		bool isFunctional() const;
		std::string serial() const;
		void informations() const;
};

class Legs {
	private:
		std::string _serial = "L-01";
		bool _functional= true;
	public:
		Legs(std::string serial = "L-01", bool functional = true);
		~Legs();
		bool isFunctional() const;
		std::string serial() const;
		void informations() const;
};

class Head {
	private:
		std::string _serial = "H-01";
		bool _functional= true;
	public:
		Head(std::string serial = "H-01", bool functional = true);
		~Head();
		bool isFunctional() const;
		std::string serial() const;
		void informations() const;
};

#endif /* !PARTS_HPP_ */
