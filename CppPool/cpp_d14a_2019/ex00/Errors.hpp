/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");

        std::string const &getComponent() const {return _component;};
        const char *what() const noexcept {return _message.c_str();};
    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};

#endif
