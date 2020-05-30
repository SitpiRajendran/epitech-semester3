/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "Object.hpp"
#include "ITable.hpp"

class PapaXmasTable : public ITable {
	public:
		PapaXmasTable();
		~PapaXmasTable();
		void putTable(Object *);
		Object *takeTable();
		Object *takeTable(int pos);
		std::string *lookTable();
		ITable *createTable();
		int last_place();
		void free_table();
		int isToy() const;
		int isBox() const;
		int isPaper() const;
	protected:
	private:
};

#endif /* !PAPAXMASTABLE_HPP_ */
