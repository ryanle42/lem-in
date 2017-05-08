/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:25:56 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:34:35 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	get_max_links(t_data *data)
{
	int	i;

	data->max_links = 0;
	i = 0;
	while (i < data->doc_size)
	{
		if (valid_link(data->doc[i]))
			data->max_links++;
		i++;
	}
}

void	get_links(t_data *data)
{
	int	i;
	int	j;

	get_max_links(data);
	data->links = (char **)malloc(sizeof(char *) * data->max_links);
	i = 0;
	j = 0;
	while (i < data->doc_size)
	{
		if (valid_link(data->doc[i]))
			data->links[j++] = ft_copystr(data->doc[i]);
		i++;
	}
}
