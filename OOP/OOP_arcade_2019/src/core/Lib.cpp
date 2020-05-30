/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Lib
*/

#include "Lib.hpp"

Lib::Lib()
{
}

Lib::~Lib()
{
}

std::vector<std::string> Lib::getGamelib()
{
    // /game/*.so

    DIR *dpdf;
    struct dirent *epdf;
    std::vector<std::string> fn;
    std::vector<std::string> fnso;
    dpdf = opendir("./game");
    if (dpdf != NULL) {
        while ((epdf = readdir(dpdf))) {
            fn.push_back(std::string(epdf->d_name));
           // std::cout << epdf->d_name << std::endl;/// DEBUG
        }
    }
    for (int i = 0; i < fn.size(); i++) {
        if(fn[i].substr(fn[i].find_last_of(".") + 1) == "so") {
            fnso.push_back(std::string(fn[i]));
        }
    }
    return (fnso);
}

std::vector<std::string> Lib::getGraphLib()
{
    // /src/lib/*.so
    DIR *dpdf;
    struct dirent *epdf;
    std::vector<std::string> fn;
    std::vector<std::string> fnso;
    dpdf = opendir("./lib");
    if (dpdf != NULL) {
        while ((epdf = readdir(dpdf))) {
            fn.push_back(std::string(epdf->d_name));
        //    std::cout << epdf->d_name << std::endl; /// DEBUG
        }
    }
    for (int i = 0; i < fn.size(); i++) {
        if(fn[i].substr(fn[i].find_last_of(".") + 1) == "so") {
            fnso.push_back(std::string(fn[i]));
        }
    }
    closedir(dpdf);
    return (fnso);
}