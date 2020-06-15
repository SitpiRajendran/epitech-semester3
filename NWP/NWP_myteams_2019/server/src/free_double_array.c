/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** free_double_array
*/

#include <stdlib.h>

void free_double_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
