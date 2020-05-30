/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy {
	public:
        Toy();
        Toy(int typeY, std::string name, std::string str);
	~Toy();
        enum ToyType {BASIC_TOY, ALIEN};
        int getType() const {return _type;};
        std::string getName() const {return _name;};
        void setName(std::string name);
        void setAscii(std::string ascii);
        std::string getAscii() const {return _file.data;};
	protected:
        int _type;
        std::string _name;
        Picture _file;
	private:
};

#endif /* !TOY_HPP_ */
