/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator do_find(T &temp, int a) {
    return (std::find(temp.begin(), temp.end(), a));
}


#endif /* !FIND_HPP_ */
