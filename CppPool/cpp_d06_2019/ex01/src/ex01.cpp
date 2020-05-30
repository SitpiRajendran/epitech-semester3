/*
** EPITECH PROJECT, 2020
** CppPool - d06
** File description:
** ex01
*/

#include <iostream>
#include <iomanip>
#include <string>

int main(void)
{
    std::string str1 ("Celsius");
    std::string str2 ("Fahrenheit");
    std::string mystr;
    float i;
    std::cin >> i >> mystr;
    std::cout << std::setprecision(3) << std::fixed;

    if (mystr.compare(str1) == 0) {
        i = i * (9.0 / 5.0) + 32;
        std::cout << std::setw(16);
        std::cout << i << std::setw(16) << str2 << std::endl;
    } else if (mystr.compare(str2) == 0) {
        i = (5.0 / 9.0) * (i - 32);
        std::cout << std::setw(16);
        std::cout << i << std::setw(16) << str1 << std::endl;
    }
    return 0;
}