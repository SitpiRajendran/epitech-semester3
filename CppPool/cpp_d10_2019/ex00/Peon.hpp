/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string nom);
		~Peon();
        void getPolymorphed() const;
	protected:
	private:
};

#endif /* !PEON_HPP_ */
