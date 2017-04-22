/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:26:54 by rle               #+#    #+#             */
/*   Updated: 2017/04/21 19:03:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_first_num()
{
	char *line;
	int i;
	int total;

	get_next_line(0, &line);
	total = 0;
	i = 0;
	while (ft_isdigit(line[i]))
	{
		total *= 10;
		total += line[i] - '0';
		i++;
	}
	return (total);
}

char **store_doc(t_link *head)
{
	t_link *current;
	char **doc;
	int i;

	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	current = head;
	doc = (char**)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (current)
	{
		doc[i] = ft_copystr(current->line);
		current = current->next;
		i++;
	}
	doc[i] = NULL;
	return (doc);
}

char **get_doc()
{
	t_link *file;
	t_link *current;
	char *line;

	if (get_next_line(0, &line))
	{
		file = (t_link*)malloc(sizeof(t_link));
		file->line = line;
		file->next = NULL;
	}
	current = file;
	while (get_next_line(0, &line))
	{
		current->next = (t_link*)malloc(sizeof(t_link));
		current = current->next;
		current->line = line;
		current->next = NULL;
	}
	return (store_doc(file));
}