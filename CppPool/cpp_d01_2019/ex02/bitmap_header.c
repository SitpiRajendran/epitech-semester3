/*
** EPITECH PROJECT, 2020
** Cpp_day01 - ex02
** File description:
** bitmap.c
*/

#include "bitmap.h"


void make_bmp_header(bmp_header_t *header, size_t size)
{
    int nb = 0x424D;
    char *c = (char *)&nb;

    if (*c)
        header->magic = htobe16(0x424d);
    else
        header->magic = 0x424D;
    header->size = (size * size * 4) + 54;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = 54;
}

void make_bmp_info_header(bmp_info_header_t *header , size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}