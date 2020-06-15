/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_channel header
*/

#ifndef MY_CHANNEL_H_
#define MY_CHANNEL_H_

#include "logging_server.h"
#include "definitions.h"

channel_t *create_channel(const char *name, const char *desc, uuid_t team_uuid);

void add_channel(channel_t **channels, channel_t *channel_to_add);

channel_t *get_channel_from_uuid(uuid_t uuid, channel_t *channels);

channel_t *get_channel_from_id(const char *id, channel_t *channels);

#endif /* !MY_CHANNEL_H_ */
