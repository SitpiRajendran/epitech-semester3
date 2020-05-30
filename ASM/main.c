/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** main
*/

#include <stdio.h>
int strcspn(const char *str1, const char *str2);

int main()
{
    int size;
    char str1[] = "geeksforgeeks";
    char str2[] = "abc";

    size = strcspn(str1, str2);
    printf("The unmatched characters before first matched character :  %d\n", size);
}
