/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** utilities
*/

#ifndef UTILITIES_H_
#define UTILITIES_H_

void free_double_array(char **array);
char *copy_word(char **dest, const char *word);
int is_token(char c, const char *tokens);
int get_word_size(char *str, const char *tokens);
int get_words_nbr(const char *str, const char *tokens);
char **split_message(char *str, const char *tokens);
int how_many_words(char **tab);
#endif /* !UTILITIES_H_ */
