/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:26:54 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:29:58 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		get_first_num(void)
{
	char	*line;
	int		i;
	int		total;

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

void	store_doc(t_link *head, t_data *data)
{
	t_link	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	current = head;
	data->doc = (char**)malloc(sizeof(char *) * i);
	data->doc_size = i;
	i = 0;
	while (current)
	{
		data->doc[i] = ft_copystr(current->line);
		current = current->next;
		i++;
	}
}

void	free_link(t_link *head)
{
	t_link	*curr;

	curr = head;
	while (curr->next)
	{
		curr = curr->next;
		free(head->line);
		free(head);
		head = curr;
	}
	free(curr->line);
	free(curr);
}

void	get_doc(t_data *data)
{
	t_link	*file;
	t_link	*current;
	char	*line;

	if (-1 == (get_next_line(0, &line)))
		return ;
	file = (t_link*)malloc(sizeof(t_link));
	file->line = ft_copystr(line);
	file->next = NULL;
	free(line);
	current = file;
	while (get_next_line(0, &line))
	{
		current->next = (t_link*)malloc(sizeof(t_link));
		current = current->next;
		current->line = ft_copystr(line);
		free(line);
		current->next = NULL;
	}
	free(line);
	store_doc(file, data);
	free_link(file);
}
