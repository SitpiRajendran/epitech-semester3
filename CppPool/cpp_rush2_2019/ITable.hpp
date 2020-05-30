/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "ITable.hpp"
#include "Object.hpp"
#include <string>

class ITable {
	public:
		ITable();
		virtual ~ITable() = 0;
		virtual void putTable(Object *) = 0;
		virtual Object *takeTable() = 0;
		virtual Object *takeTable(int pos) = 0;
		virtual std::string *lookTable() = 0;
		virtual ITable *createTable() = 0;
		virtual int isToy() const = 0;
		virtual int isBox() const = 0;
		virtual int isPaper() const = 0;
	protected:
		Object *_array[10];
	private:
};

#endif /* !ITABLE_HPP_ */