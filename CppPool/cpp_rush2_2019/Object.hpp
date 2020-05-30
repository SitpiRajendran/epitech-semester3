/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>

class Object {
	public:
		Object(const std::string &title);
		~Object();
		std::string getTitle(void) {return _title;};
		int getID(void) const {return _id;};
		virtual Object *getObject(void) const = 0;
		enum {NOTHING, TEDDY, LITTLEPONY, BOX, GIFTPAPER};
	protected:
		std::string _title;
		int _id;
	private:
};

Object *MyUnitTests(Object **items);
Object **MyUnitTests(void);
#endif /* !OBJECT_HPP_ */