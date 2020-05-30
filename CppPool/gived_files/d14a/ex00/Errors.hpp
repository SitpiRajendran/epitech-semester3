
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");

        std::string const &getComponent() const;
    private:
        std::string _message;
};

class MissionCriticalError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class LifeCriticalError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class UserError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
};

class CommunicationError
{
    public:
        CommunicationError(std::string const &message);
};

#endif
