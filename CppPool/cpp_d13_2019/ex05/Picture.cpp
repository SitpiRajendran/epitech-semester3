/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    if (file == "")
        data = "";
    else
        getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream ifs (file);
    std::ostringstream ss;

    if (ifs.is_open()) {
        ss << ifs.rdbuf();
        data = ss.str();
        return true;
    } else {
        data = "ERROR";
        return false;
    }
}

Picture &Picture::operator=(const Picture &old)
{
    if (this == &old)
        return *this;

    data = old.data;
    return *this;
}