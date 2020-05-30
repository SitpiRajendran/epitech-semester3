/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Elf
*/

#ifndef ELF_HPP_
#define ELF_HPP_

#include "Table.hpp"
#include "Object.hpp"
#include "Hand.hpp"
#include "IElf.hpp"

class Elf : public IElf {
	public:
		Elf();
		~Elf();
		Object *MakeToy(Table *tab);
		Hand *UseHand() const;
	protected:
	private:
};

#endif /* !ELF_HPP_ */
