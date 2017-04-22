/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:12:26 by rle               #+#    #+#             */
/*   Updated: 2017/04/21 19:46:12 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int get_start(char **doc)
{
	int i;
	int room;

	room = 0;
	i = 0;
	while (doc[i])
	{
		if (!ft_strcmp("##start", doc[i]))
			return (room);
		if (valid_room(doc[i]))
			room++;
		i++;
	}
	return (-1);
}

int get_end(char **doc)
{
	int i;
	int room;

	room = 0;
	i = 0;
	while (doc[i])
	{
		if (!ft_strcmp("##end", doc[i]))
			return (room);
		if (valid_room(doc[i]))
			room++;
		i++;
	}
	return (-1);
}

t_data	get_data()
{
	t_data data;

	data.doc = get_doc();
	data.max_rooms = get_max_rooms(data.doc);
	data.rooms = get_rooms(data.doc);
	data.links = get_links(data.doc);
	if ((data.start = get_start(data.doc)) < 0)
		printf("error\n");
	if ((data.end = get_end(data.doc)) < 0)
		printf("error\n");
	return (data);
}