/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:02:55 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 19:27:03 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		free_links(t_links *head)
{
	t_links	*curr;

	curr = head;
	while (curr->next)
	{
		curr = curr->next;
		free(head);
		head = curr;
	}
	free(curr);
}

static void		free_rooms(t_room *rooms, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(rooms[i].name);
		free_links(rooms[i].links);
		i++;
	}
	free(rooms);
}

static void		free_strings(char **str, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(str[i]);
		i++;
	}
}

static void		free_ints(int **arr, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(arr[i]);
		i++;
	}
}

void			let_it_go(t_data *data, t_room *rooms, t_links *head)
{
	free_rooms(rooms, data->max_rooms);
	free_strings(data->doc, data->doc_size);
	free(data->doc);
	free_strings(data->rooms, data->max_rooms);
	free(data->rooms);
	free_strings(data->links, data->max_links);
	free(data->links);
	free_ints(data->map, data->max_rooms);
	free(data->map);
	free_links(head);
}
