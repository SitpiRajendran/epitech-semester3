/*
** EPITECH PROJECT, 2020
** CppPool - d6
** File description:
** ex3 - KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"
#include <fstream>
#include <sstream>

class KoalaNurse {
	public:
        int id;
		bool working;
		KoalaNurse(int val);
		~KoalaNurse();
        void giveDrug(std::string str, SickKoala *patient);
        std::string readReport(std::string file);
		void timeCheck(void);
		int getID();
	protected:
	private:
};

#endif /* !KOALANURSE_HPP_ */
