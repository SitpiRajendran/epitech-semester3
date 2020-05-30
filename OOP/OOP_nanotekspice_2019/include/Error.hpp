/*
** EPITECH PROJECT, 2020
** Error.hpp
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "Parser.hpp"
#include <exception>

class Error : public std::exception {
    public:
        Error(std::string const& error="") throw()
        {
            this->description = error;
        }
        virtual const char *what() const throw()
        {
            return description.c_str();
        }
        virtual ~Error() throw()
        {}

    protected:
    private:
        std::string description;
};

#endif /* !ERROR_HPP_ */
