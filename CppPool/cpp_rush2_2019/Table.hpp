/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Table
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_

#include "ITable.hpp"
#include "Object.hpp"
#include <string>

class Table : public ITable {
	public:
		Table();
		~Table();
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

#endif /* !TABLE_HPP_ */
