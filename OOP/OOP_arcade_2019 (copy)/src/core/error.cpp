/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** error
*/

#include "error.hpp"

Error::Error(std::string const &message)
: _message(message)
{}

const char *Error::what() const noexcept {
    return (_message.data());
}

ArgvError::ArgvError(std::string const &message)
: Error(message)
{}