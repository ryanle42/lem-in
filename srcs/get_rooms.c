/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:18:16 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 19:25:32 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		check_coords(t_coord *coord, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j < max)
		{
			if (coord[i].x == coord[j].x && \
				coord[i].y == coord[j].y)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_names(char **rooms, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j < max)
		{
			if (0 == ft_strcmp(rooms[i], rooms[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_rooms(t_data *data)
{
	int		i;
	int		j;
	t_coord	*coord;

	get_max_rooms(data);
	data->rooms = (char **)malloc(sizeof(char*) * data->max_rooms);
	coord = (t_coord*)malloc(sizeof(t_coord) * data->max_rooms);
	i = -1;
	j = -1;
	while (++i < data->doc_size)
	{
		if (valid_room(data->doc[i]))
		{
			data->rooms[++j] = get_name(data->doc[i]);
			get_coord(data->doc[i], &coord[j]);
			if ((-1 == check_names(data->rooms, j)) || \
				(-1 == check_coords(coord, j)))
			{
				printf("line: %i\n", i);
				printf("ERROR: Duplicate name or coordinate\n");
				exit(1);
			}
		}
	}
	free(coord);
}
