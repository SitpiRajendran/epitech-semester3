/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** split_message
*/

#include <string.h>
#include <stdlib.h>
#include "utilities.h"

int get_word(char **word, char *str, const char *tokens)
{
    int word_size = get_word_size(str, tokens);

    *word = malloc(sizeof(char) * (word_size + 1));
    if (*word == NULL) {
        return (-1);
    }
    strncpy(*word, str, word_size);
    (*word)[word_size] = 0;
    return (word_size);
}

int get_string(char **word, char *str)
{
    int size = 0;

    for (; str[size] != '\0' && str[size] != '"'; size++);
    *word = malloc(sizeof(char) * (size + 1));
    if (*word == NULL) {
        return (-1);
    }
    strncpy(*word, str, size);
    (*word)[size] = 0;
    if (str[size] == 0) {
        return (size);
    }
    return (size + 1);
}

char **split_message(char *str, const char *tokens)
{
    int pos = 0;
    char **words = malloc(sizeof(char *) * (get_words_nbr(str, tokens) + 1));

    if (words == NULL || get_words_nbr(str, tokens) == 0) {
        return (NULL);
    }
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '"') {
            i += get_string(&words[pos], &str[i + 1]);
            pos++;
        } else if (!is_token(str[i], tokens)) {
            i += get_word(&words[pos], &str[i], tokens);
            pos++;
        }
    }
    words[pos] = NULL;
    return (words);
}

int how_many_words(char **tab)
{
    int i = 0;

    while (tab[i++]);

    return i-1;
}