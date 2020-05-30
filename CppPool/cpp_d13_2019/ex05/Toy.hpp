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
        Toy(int type = BASIC_TOY, std::string name = "toy", std::string str= "");
        Toy(Toy const &old) : _type(old._type), _name(old._name), _file(old._file){};
        ~Toy();

        Toy &operator=(Toy const &old);
        Toy &operator<<(const std::string str);

        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};

        int getType() const {return _type;};
        std::string getName() const {return _name;};
        void setName(std::string name);
        bool setAscii(std::string ascii);
        std::string getAscii() const {return _file.data;};

        virtual void speak(std::string str);
        virtual bool speak_es(std::string str);

        class Error {
            public :
                Error() {type = UNKNOWN;};
                enum ErrorType {UNKNOWN, PICTURE, SPEAK};
                std::string what() const;
                std::string where() const;
                void setError(ErrorType t);
                ErrorType type;
        };

        Error getLastError() {return _err;};
    protected:
        int _type;
        std::string _name;
        Picture _file;
        Error _err;
    private:
};

std::ostream &operator<<(std::ostream &out, const Toy &droid);
#endif /* !TOY_HPP_ */
