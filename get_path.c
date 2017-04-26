/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:55:49 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 21:08:54 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int find_path(int *paths, int *used, t_data *data, int i)
{
	int j;

	j = 0;
	if (i == data->end)
		return (1);
	while (j < data->max_rooms)
	{
		if (data->map[i][j] == 1 && !used[j])
		{
			used[j] = 1;
			if (find_path((paths + 1), used, data, j))
			{
				*paths = j;
				data->pathsize++;
				return (1);
			}
		}
		j++;
	}
	return (0);
}

t_links *get_path(t_data data, t_room *rooms)
{
	int *paths;
	int *used;
	int pathsize;
	t_links *head;
	t_links *current;
	int i;

	paths = (int *)malloc(sizeof(int) * data.max_rooms);
	used = (int *)malloc(sizeof(int) * data.max_rooms);
	data.pathsize = 0;
	ft_bzero(paths,sizeof(paths));
	ft_bzero(used, sizeof(used));
	used[data.start] = 1;
	*paths = data.start; 
	find_path(paths + 1, used, &data, 1);
	i = data.pathsize;
	head = (t_links*)malloc(sizeof(t_links));
	head->room = &rooms[paths[i]];
	current = head;
	i--;
	while (i >= 0)
	{
		current->next = (t_links*)malloc(sizeof(t_links));
		current = current->next;
		current->room = &rooms[paths[i]];
		i--;
	}
	return (head);
}