/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:54:29 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 23:15:31 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int	**init_map(t_data data)
{
	int	**map;
	int	x;
	int	y;

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

int	**make_map(t_data data)
{
	int	**map;
	int	i;
	int	y;
	int	x;

	map = init_map(data);
	i = 0;
	while (i < data.max_links)
	{
		if ((-1 == (y = check_id(data, i, 0))) || \
			(-1 == (x = check_id(data, i, 1))))
		{
			ft_printf("ERROR: invalid links\n");
			exit(1);
		}
		map[y][x] = 1;
		map[x][y] = 1;
		i++;
	}
	return (map);
}
