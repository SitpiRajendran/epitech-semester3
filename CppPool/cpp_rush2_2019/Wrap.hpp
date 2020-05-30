/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object {
	public:
		Wrap(const std::string &title);
		~Wrap();
        void openMe();
        void closeMe();
		virtual void wrapMeThat(Object *object);
		void isTaken();
		Object *getObject(void) const {return (this->_object);};
	protected:
        bool _isOpen;
        Object *_object;
	private:
};

#endif /* !WRAP_HPP_ */