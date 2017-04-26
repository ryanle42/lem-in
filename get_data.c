/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:12:26 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 20:00:55 by rle              ###   ########.fr       */
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

int		get_id(t_data data, char *name)
{
	int i;

	i = 0;
	while (data.rooms[i])
	{
		if (!ft_strcmp(data.rooms[i], name))
			return (i);
		i++;
	}
	return (-1);
}

char *get_link_num(char *link, int n)
{
	int i;
	int j;
	char *c;

	i = 0;
	while (link[i] != '-')
		i++;
	c = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (link[i] != '-')
	{
		c[i] = link[i];
		i++;
	}
	c[i] = '\0';
	if (n == 0)
		return (c);
	free(c);
	i++;
	j = 0;
	while (link[i + j])
		j++;
	c = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (link[i])
	{
		c[j] = link[i];
		j++;
		i++;
	}
	c[j] = '\0';
	return (c);
}

int	get_ants(char **doc)
{
	char *line;
	int i;
	int num;

	num = 0;
	i = 0;
	line = ft_copystr(doc[i]);
	while (line[i] && ft_isdigit(line[i]))
	{
		num *= 10;
		num += line[i] - '0';
		i++;
	}
	if (line[i])
		return (-1);
	return (num);
}

t_data	get_data()
{
	t_data data;

	data.doc = get_doc();
	data.max_rooms = get_max_rooms(data.doc);
	data.rooms = get_rooms(data.doc);
	data.links = get_links(data.doc);
	data.ants = get_ants(data.doc);
	if ((data.start = get_start(data.doc)) < 0)
		printf("error\n");
	if ((data.end = get_end(data.doc)) < 0)
		printf("error\n");
	return (data);
}