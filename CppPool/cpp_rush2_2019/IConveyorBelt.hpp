/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_

#include "Wrap.hpp"
#include "Object.hpp"

class IConveyorBelt {
	public:
		IConveyorBelt();
		virtual ~IConveyorBelt() = 0;
		virtual void putObject(Object *) = 0;
		virtual Object *takeObject(void) = 0;
		virtual void santaVanished(void) = 0;
		virtual Wrap *IN(void) = 0;
		virtual void OUT(void) = 0;
		virtual IConveyorBelt *createConveyorBelt(void) = 0;
	protected:
		Object *_object;
};

#endif /* !ICONVEYORBELT_HPP_ */