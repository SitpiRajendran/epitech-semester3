/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>

class Picture {
	public:
		Picture(const std::string &file = "");
		~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
	protected:
	private:
};

#endif /* !PICTURE_HPP_ */
