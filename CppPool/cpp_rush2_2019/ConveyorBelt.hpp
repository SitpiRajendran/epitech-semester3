/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** ConveyorBelt
*/

#ifndef CONVEYORBELT_HPP_
#define CONVEYORBELT_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include "IConveyorBelt.hpp"

class ConveyorBelt : public IConveyorBelt {
	public:
		ConveyorBelt();
		~ConveyorBelt();
		void putObject(Object *);
		Object *takeObject(void);
		void santaVanished(void);
		Wrap *IN(void);
		void OUT(void);
		IConveyorBelt *createConveyorBelt(void);
};

#endif /* !CONVEYORBELT_HPP_ */
