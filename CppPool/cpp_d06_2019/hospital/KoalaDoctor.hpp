/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
	public:
    	std::string name;
		bool working;
		KoalaDoctor(std::string str);
		~KoalaDoctor();
        void diagnose(SickKoala *patient);
		void timeCheck(void);
		std::string getName();
	protected:
	private:
};

#endif /* !KOALADOCTOR_HPP_ */
