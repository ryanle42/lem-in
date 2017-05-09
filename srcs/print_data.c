/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 23:13:49 by rle               #+#    #+#             */
/*   Updated: 2017/05/08 14:06:45 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_info(t_data data)
{
	int	i;

	i = -1;
	while (++i < data.max_rooms)
		ft_printf("room:%s\n", data.rooms[i]);
	i = 0;
	while (i < data.max_links)
	{
		ft_printf("link:%s\n", data.links[i]);
		i++;
	}
	ft_printf("rooms:%i\n", data.max_rooms);
	ft_printf("start: %s\n", data.rooms[data.start]);
	ft_printf("end: %s\n", data.rooms[data.end]);
	ft_printf("ants: %i\n", data.ants);
	ft_printf("\n");
}

void	print_rooms(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.max_rooms)
	{
		ft_printf("%i ", i % 10);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < data.max_rooms)
	{
		j = 0;
		ft_printf("%i  ", i % 10);
		while (j < data.max_rooms)
		{
			ft_printf("%i ", data.map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_links(t_data data, t_room *rooms, t_links *current)
{
	int		i;
	t_links	*tmp;

	i = -1;
	ft_printf("\nid | name | links");
	while (++i < data.max_rooms)
	{
		ft_printf("\n\n%i    %s    ", \
			get_id(data, rooms[i].name), rooms[i].name);
		if (rooms[i].links->room)
			ft_printf(" %s", rooms[i].links->room->name);
		tmp = rooms[i].links;
		while (tmp->next)
		{
			tmp = tmp->next;
			ft_printf(" %s", tmp->room->name);
		}
	}
	ft_printf("\n\npath:%s\n", current->room->name);
	while (current->next)
	{
		current = current->next;
		ft_printf("path:%s\n", current->room->name);
	}
	ft_printf("\n");
}

void	print_doc(t_data data)
{
	int	i;

	i = 0;
	while (i < data.doc_size)
	{
		ft_printf("%s\n", data.doc[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_data(t_data data, t_room *rooms, t_links *current)
{
	t_links	*tmp;

	tmp = current;
	print_info(data);
	ft_printf("   ");
	print_rooms(data);
	print_links(data, rooms, current);
}
