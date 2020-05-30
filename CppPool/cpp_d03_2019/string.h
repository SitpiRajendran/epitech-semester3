/*
** EPITECH PROJECT, 2020
** cpp_d03 - ex00
** File description:
** string.h
*/

#ifndef STRING_H_
#define STRING_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct string_s
{
    char *str;
    void (*init)(struct string_s *this, const char *s);
    void (*destroy)(struct string_s *this);
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*assign_c)(struct string_s *this, const char *s);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*size)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *s);
    int (*compare_c)(const struct string_s *this, const char *s);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char * (*c_str)(const struct string_s *this);
    int (*empty)(const struct string_s *this);
    int (*find_s)(const struct string_s *, const struct string_s *, size_t);
    int (*find_c)(const struct string_s *this, const char *str, size_t pos);
    void (*insert_c)(struct string_s *this, size_t pos, const char *str);
    void (*insert_s)(struct string_s *, size_t , const struct string_s *);
    int (*to_int)(const struct string_s *this);
} string_t;

void string_init(string_t *this, const char *s);
void string_allinit(string_t *this);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *s);
int compare_c(const string_t *this, const char *s);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
#endif /* !STRING_H_ */
