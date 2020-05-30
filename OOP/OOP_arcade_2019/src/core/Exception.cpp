/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** error
*/

#include "Exception.hpp"

Exception::Exception(std::string const &message)
: _message(message)
{}

Exception::~Exception() throw()
{}

const char *Exception::what() const throw(){
    return (_message.c_str());
}