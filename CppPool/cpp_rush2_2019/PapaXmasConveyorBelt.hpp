/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
#define PAPAXMASCONVEYORBELT_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt {
	public:
		PapaXmasConveyorBelt();
		~PapaXmasConveyorBelt();
		void putObject(Object *);
		Object *takeObject(void);
		void santaVanished(void);
		Wrap *IN(void);
		void OUT(void);
		IConveyorBelt *createConveyorBelt(void);
};

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
