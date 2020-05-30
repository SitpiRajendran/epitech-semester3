/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
	private:
        std::string _name;
        int _stim;
	public:
	    Skat(const std::string &name, int stimPaks);
        Skat(const std::string &name);
        Skat(int stimPaks);
        Skat(void);
		~Skat();

        int &stimPaks();
        const std::string &name();

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
};

#endif /* !SKAT_HPP_ */