/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:19:12 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 19:22:47 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_x(char *line)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		n *= 10;
		n += line[i] - '0';
		i++;
	}
	return (n);
}

static int	get_y(char *line)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		n *= 10;
		n += line[i] - '0';
		i++;
	}
	return (n);
}

void		get_coord(char *line, t_coord *coord)
{
	coord->x = get_x(line);
	coord->y = get_y(line);
}

char		*get_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	name = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (line[i] && line[i] != ' ')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

void		get_max_rooms(t_data *data)
{
	int	i;

	data->max_rooms = 0;
	i = 0;
	while (i < data->doc_size)
	{
		if (valid_room(data->doc[i]))
			data->max_rooms++;
		i++;
	}
}
