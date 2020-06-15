/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** ErrorHandling
*/

#include <cstddef>
#include <ostream>
#include <iostream>

#include "ErrorHandling.hpp"

using namespace std;
indie::ErrorHandling::ErrorHandling() {}
indie::ErrorHandling::~ErrorHandling() {}

bool indie::ErrorHandling::env_handling(char **env) {
    if (!env || !env[0])
        return false;
    for (size_t i = 0; env[i]; i ++) {
        if (string(env[i]).find("DISPLAY=:") != string::npos)
            return true;
    }
    return false;
}