/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:10:49 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:11:56 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		valid_room(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'L' || line[i] == '#')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (0);
	i++;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (!line[i])
		return (0);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
}

int		valid_link(char *line)
{
	int	i;

	i = 0;
	if (!line[i] || line[i] == 'L' || line[i] == '#')
		return (0);
	while (line[i] && line[i] != '-')
		i++;
	if (!line[i])
		return (0);
	i++;
	if (!line[i] || line[i] == 'L' || line[i] == '#')
		return (0);
	return (1);
}

int		valid_start_end(t_data data, char *keyword)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data.doc_size)
	{
		if (0 == ft_strcmp(data.doc[i], keyword))
		{
			i++;
			while (i < data.doc_size && data.doc[i][0] == '#' \
				&& ft_strcmp(data.doc[i], "##end") && \
				ft_strcmp(data.doc[i], "##start"))
				i++;
			if (i > data.doc_size || !valid_room(data.doc[i]))
				return (0);
			count++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}
