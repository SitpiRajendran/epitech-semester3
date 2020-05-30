/*
** EPITECH PROJECT, 2020
** CppPool - D09
** File description:
** ex00
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("----\nBuilding %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(new);

    return new;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power < 42)
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    else {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    }
}
void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *_name, char  _is_A_Legend)
{
    cthulhu_initializer(&this->m_parent);
    this->m_parent.m_name = _name;
    this->m_is_a_legend = _is_A_Legend;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    koala_initializer(new, name, is_a_legend);
    if (is_a_legend == 1)
        printf("Building Legend\n");
    else {
        printf("Building NotLegend\n");
        new->m_parent.m_power = 0;
    }
    return new;
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}