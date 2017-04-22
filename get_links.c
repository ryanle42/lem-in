/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:25:56 by rle               #+#    #+#             */
/*   Updated: 2017/04/21 19:36:00 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		valid_link(char *line)
{
	int i;

	i = 0;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!line[i])
		return (0);
	if (line[i] != '-')
		return (0);
	i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int		get_max_links(char **doc)
{
	int i;
	int max_links;

	max_links = 0;
	i = 0;
	while (doc[i])
	{
		if (valid_link(doc[i]))
			max_links++;
		i++;
	}
	return (max_links);
}

char **get_links(char **doc)
{
	int i;
	int j;
	int max_links;
	char **links;

	max_links = get_max_links(doc);
	links = (char **)malloc(sizeof(char *) * max_links + 1);
	i = 0;
	j = 0;
	while (doc[i])
	{
		if (valid_link(doc[i]))
			links[j++] = doc[i];
		i++;
	}
	links[j] = NULL;
	return (links);
}