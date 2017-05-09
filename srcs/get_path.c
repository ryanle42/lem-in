/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:55:49 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:48:19 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			find_path(int *paths, int *used, t_data *data, int i)
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

static void	prep_path(t_data *data, int *paths, int *used)
{
	used[data->start] = 1;
	*paths = data->start;
	data->pathsize = 0;
}

static void	connect_path(t_data data, t_room *rooms,
				t_links *head, int *paths)
{
	t_links *current;

	head->room = &rooms[paths[data.pathsize]];
	current = head;
	data.pathsize--;
	while (data.pathsize >= 0)
	{
		current->next = (t_links*)malloc(sizeof(t_links));
		current = current->next;
		current->room = &rooms[paths[data.pathsize]];
		data.pathsize--;
	}
	current->next = NULL;
}

t_links		*get_path(t_data data, t_room *rooms)
{
	int		*paths;
	int		*used;
	t_links	*head;

	head = (t_links*)malloc(sizeof(t_links));
	paths = (int *)malloc(sizeof(int) * data.max_rooms);
	used = (int *)malloc(sizeof(int) * data.max_rooms);
	ft_bzero(paths, sizeof(int) * data.max_rooms);
	ft_bzero(used, sizeof(int) * data.max_rooms);
	prep_path(&data, paths, used);
	if (!find_path(paths + 1, used, &data, data.start))
	{
		ft_printf("ERROR: No path to end\n");
		exit(1);
	}
	connect_path(data, rooms, head, paths);
	free(paths);
	free(used);
	return (head);
}
