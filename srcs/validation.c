/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:32:26 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:13:41 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	valid_ants(char *line)
{
	int	i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	validate_ants(t_data data)
{
	int	i;

	i = 0;
	if (!data.doc[i])
		return (0);
	while (i < data.doc_size && data.doc[i][0] == '#')
		i++;
	if (!valid_ants(data.doc[i]))
		return (0);
	return (1);
}

int	valid_data(t_data data, int i, int info)
{
	while (i < data.doc_size && data.doc[i][0] == '#')
		i++;
	if (!valid_ants(data.doc[i]))
	{
		printf("ERROR: invalid ants\n");
		exit(1);
		return (0);
	}
	i++;
	while (i < data.doc_size)
	{
		if (valid_link(data.doc[i]) && info == 0)
		{
			info++;
			i++;
		}
		else if ((valid_room(data.doc[i]) && info == 0) || \
			(valid_link(data.doc[i]) && info == 1) || \
			(data.doc[i][0] == '#'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	validate_doc(t_data data)
{
	if (!(valid_start_end(data, "##start") && valid_start_end(data, "##end")))
	{
		printf("ERROR: invalid start/end\n");
		exit(1);
	}
	if (!valid_data(data, 0, 0))
	{
		printf("ERROR: invalid map\n");
		exit(1);
	}
	return (1);
}
