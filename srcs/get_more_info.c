/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_more_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:01:33 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 23:15:29 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	get_start(t_data *data)
{
	int	i;

	data->start = 0;
	i = 0;
	while (i < data->doc_size && ft_strcmp(data->doc[i], "##start"))
	{
		if (valid_room(data->doc[i]))
			data->start++;
		i++;
	}
}

void	get_end(t_data *data)
{
	int	i;

	data->end = 0;
	i = 0;
	while (i < data->doc_size && ft_strcmp(data->doc[i], "##end"))
	{
		if (valid_room(data->doc[i]))
			data->end++;
		i++;
	}
}

int		get_id(t_data data, char *name)
{
	int	i;

	i = 0;
	while (i < data.max_rooms)
	{
		if (!ft_strcmp(data.rooms[i], name))
			return (i);
		i++;
	}
	return (-1);
}

int		check_id(t_data data, int i, int n)
{
	char	*tmp;
	int		ret;

	tmp = get_link_num(data.links[i], n);
	ret = get_id(data, tmp);
	free(tmp);
	return (ret);
}
