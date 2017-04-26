/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:54:29 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 20:01:24 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int **init_map(t_data data)
{
	int **map;
	int x;
	int y;

	map = (int **)malloc(sizeof(int*) * data.max_rooms);
	y = 0;
	while (y < data.max_rooms)
	{
		map[y] = (int *)malloc(sizeof(int) * data.max_rooms);
		x = 0;
		while (x < data.max_rooms)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

int **make_map(t_data data)
{
	int **map;
	int i;
	int y;
	int x;

	map = init_map(data);
	i = 0;
	while (data.links[i])
	{
		y = get_id(data, get_link_num(data.links[i], 0));
		x = get_id(data, get_link_num(data.links[i], 1));
		map[y][x] = 1;
		map[x][y] = 1;
		i++;
	}
	return (map);
}