/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
	private:
		std::string _serial = "Bob-01";
		Arms _arm;
		Legs _leg;
		Head _head;
	public:
		KoalaBot(std::string serial = "Bob-01");
		~KoalaBot();

		void setParts(const Arms&);
		void setParts(const Legs&);
		void setParts(const Head&);

		void swapParts(Arms&);
		void swapParts(Legs&);
		void swapParts(Head&);

		void informations() const;
		bool status() const;
};

#endif /* !KOALABOT_HPP_ */
