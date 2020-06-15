/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** word
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_token(char c, const char *tokens)
{
    for (int i = 0; tokens[i] != 0; i++) {
        if (c == tokens[i]) {
            return (1);
        }
    }
    return (0);
}

int get_word_size(char *str, const char *tokens)
{
    int size = 0;

    while (!is_token(str[size], tokens)) {
        size++;
    }
    return (size);
}

int get_words_nbr(char *str, const char *tokens)
{
    int words = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (!is_token(str[i], tokens) &&
        (is_token(str[i + 1], tokens) || str[i + 1] == '\0')) {
            words++;
            i += get_word_size(&str[i], tokens);
        }
    }
    return (words);
}

char *copy_word(char **dest, const char *word)
{
    *dest = malloc(sizeof(char) * (strlen(word) + 1));
    if (*dest == NULL) {
        printf("Error malloc\n");
        return (NULL);
    }
    strcpy(*dest, word);
    return (*dest);
}
