/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:18:16 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 14:13:38 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	valid_room(char *line)
{
	int i;

	i = 0;
	if (line[i] == 'L' || line[i] == '#' || line[i] == '-')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (0);
	i++;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (!line[i])
		return (0);
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_name(char *line)
{
	int i;
	char *name;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	name = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (line[i] && line[i] != ' ')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

int get_max_rooms(char **doc)
{
	int i, max_rooms;

	max_rooms = 0;
	i = 0;
	while (doc[i])
	{
		if (valid_room(doc[i]))
			max_rooms++;
		i++;
	}
	return (max_rooms);
}

char **get_rooms(char **doc)
{
	int i;
	int j;
	int max_rooms;
	char **rooms;

	max_rooms = get_max_rooms(doc);
	rooms = (char **)malloc(sizeof(char*) * max_rooms + 1);
	i = 0;
	j = 0;
	while (doc[i])
	{
		if (valid_room(doc[i]))
		{
			rooms[j] = get_name(doc[i]);
			j++;
		}
		i++;
	}
	rooms[j] = NULL;
	return (rooms);
}