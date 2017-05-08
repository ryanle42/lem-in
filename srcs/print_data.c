/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:52:33 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:39:21 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_info(t_data data)
{
	int	i;

	i = -1;
	while (++i < data.max_rooms)
		printf("room:%s\n", data.rooms[i]);
	i = 0;
	while (i < data.max_links)
	{
		printf("link:%s\n", data.links[i]);
		i++;
	}
	printf("rooms:%i\n", data.max_rooms);
	printf("start: %s\n", data.rooms[data.start]);
	printf("end: %s\n", data.rooms[data.end]);
	printf("ants: %i\n", data.ants);
	printf("\n");
}

void	print_rooms(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.max_rooms)
	{
		printf("%s ", data.rooms[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < data.max_rooms)
	{
		j = 0;
		printf("%s  ", data.rooms[i]);
		while (j < data.max_rooms)
		{
			printf("%i ", data.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_links(t_data data, t_room *rooms, t_links *current)
{
	int		i;
	t_links	*tmp;

	i = 0;
	printf("\nid | name | links");
	while (i < data.max_rooms)
	{
		printf("\n\n%i    %s    ", get_id(data, rooms[i].name), rooms[i].name);
		if (rooms[i].links->room)
			printf(" %s", rooms[i].links->room->name);
		tmp = rooms[i].links;
		while (tmp->next)
		{
			tmp = tmp->next;
			printf(" %s", tmp->room->name);
		}
		i++;
	}
	printf("\n\npath:%s\n", current->room->name);
	while (current->next)
	{
		current = current->next;
		printf("path:%s\n", current->room->name);
	}
	printf("\n");
}

void	print_data(t_data data, t_room *rooms, t_links *current)
{
	t_links	*tmp;

	tmp = current;
	print_info(data);
	printf("   ");
	print_rooms(data);
	print_links(data, rooms, current);
}
