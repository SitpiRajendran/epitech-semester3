/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

class Error : public std::exception {
    public:
        Error(std::string const &message);

        const char *what() const noexcept;
    private:
        std::string _message;
    };

class ArgvError : public Error {
    public:
        ArgvError(std::string const &message);
    };

#endif /* !ERROR_HPP_ */