/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "Table.hpp"
#include "Object.hpp"
#include "Hand.hpp"

class IElf {
	public:
		IElf();
		virtual~IElf();
        virtual Object *MakeToy(Table *tab) = 0;
	protected:
		Hand *_hand;
	private:
};

#endif /* !IELF_HPP_ */
