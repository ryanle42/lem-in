/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:34:42 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:33:59 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	init_ants(t_links *head, int ants)
{
	if (head == NULL)
		return ;
	head->space = 0;
	head->id = 0;
	head->room->property = 0;
	while (head->next)
	{
		head = head->next;
		head->room->property = 2;
		head->id = 0;
		head->space = 0;
	}
	head->room->property = 1;
	head->space = ants;
}

t_room	*make_rooms(t_data data)
{
	t_room	*rooms;
	int		i;

	rooms = (t_room *)malloc(sizeof(t_room) * data.max_rooms);
	i = 0;
	while (i < data.max_rooms)
	{
		rooms[i].name = ft_copystr(data.rooms[i]);
		if (i == data.start)
			rooms[i].property = 1;
		else if (i == data.end)
			rooms[i].property = 0;
		else
			rooms[i].property = 2;
		rooms[i].ants = 0;
		rooms[i].links = (t_links *)malloc(sizeof(t_links));
		rooms[i].links->room = NULL;
		rooms[i].links->next = NULL;
		i++;
	}
	return (rooms);
}

void	link_rooms_help(t_links *current, t_room *rooms, int j, int k)
{
	current = rooms[j].links;
	if (!current->room)
		current->room = &rooms[k];
	else
	{
		while (current->next)
			current = current->next;
		current->next = (t_links *)malloc(sizeof(t_links));
		current->next->room = &rooms[k];
		current->next->next = NULL;
	}
	current = rooms[k].links;
	if (!current->room)
		current->room = &rooms[j];
	else
	{
		while (current->next)
			current = current->next;
		current->next = (t_links *)malloc(sizeof(t_links));
		current->next->room = &rooms[j];
		current->next->next = NULL;
	}
}

t_room	*link_rooms(t_room *rooms, t_data data)
{
	int		i;
	int		j;
	int		k;
	t_links	*current;

	current = NULL;
	i = 0;
	while (i < data.max_links)
	{
		if ((-1 == (j = check_id(data, i, 0))) || \
			(-1 == (k = check_id(data, i, 1))))
		{
			printf("ERROR: invalid link: %s\n", data.links[i]);
			exit(1);
		}
		link_rooms_help(current, rooms, j, k);
		i++;
	}
	return (rooms);
}
