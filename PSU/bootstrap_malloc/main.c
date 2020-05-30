/*
** EPITECH PROJECT, 2020
** bootstrap_malloc
** File description:
** main_function
*/


#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;
    void (*cosine)(char*);

    handle = dlopen("/home/srajendran/Epitek2-S4/PSU/bootstrap_malloc/libfoo.so", RTLD_LAZY);
    cosine = dlsym(handle, "my_putstr");
    (*cosine)("Hell0String!/");
    dlclose(handle);
}

/* int main (void)
{
    my_putstr("Hello World!!!");
} */