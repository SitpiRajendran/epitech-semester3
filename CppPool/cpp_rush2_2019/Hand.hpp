/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Hand
*/

#ifndef HAND_HPP_
#define HAND_HPP_

#include "Object.hpp"

class Hand {
	public:
		Hand();
		~Hand();
        void takeObject(Object *);
        Object *checkHand() const;
        Object *putObject();
	protected:
	private:
        Object *_object;
};

#endif /* !HAND_HPP_ */
