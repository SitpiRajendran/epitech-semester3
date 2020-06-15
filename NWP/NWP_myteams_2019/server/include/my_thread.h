/*
** EPITECH PROJECT, 2020
** NWP_mythreads_2019
** File description:
** my_thread header
*/

#ifndef MY_THREAD_H_
#define MY_THREAD_H_

#include "definitions.h"

thread_t *create_thread(const char *title, const char *message,
                        uuid_t channel_uuid, uuid_t user_uuid);

void add_thread(thread_t **threads, thread_t *thread_to_add);

thread_t *get_thread_from_uuid(uuid_t uuid, thread_t *threads);

thread_t *get_thread_from_id(const char *id, thread_t *threads);

#endif /* !MY_THREAD_H_ */
