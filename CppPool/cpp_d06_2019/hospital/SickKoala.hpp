/*
** EPITECH PROJECT, 2020
** CppPool - d06
** File description:
** exo02 - SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>
#include <string>

class SickKoala {
	public:
		SickKoala(std::string string);
		~SickKoala(void);
		void poke(void);
		bool takeDrug(std::string str);
		void overDrive(std::string str);
		std::string getName(void);
	protected:
		std::string name;
	private:
};

#endif /* !SICKKOALA_HPP_ */
