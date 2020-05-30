/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include <iostream>
#include "Wrap.hpp"

class GiftPaper : public Wrap{
	public:
		GiftPaper(const std::string &title = "Paper");
		~GiftPaper();
		void wrapMeThat(Object *object);
	protected:
	private:
};

#endif /* !GIFTPAPER_HPP_ */
