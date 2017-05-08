/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:32:30 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 19:26:01 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	ans_help(t_links *current)
{
	printf("L%i-%s ", current->next->id, current->room->name);
	current->id = current->next->id;
	current->space++;
	current->next->space = 0;
}

void		print_ans(t_links *head, t_links *current, t_data data, int ant)
{
	while (head->id != data.ants)
	{
		current = head;
		while (current->next)
		{
			if (current->space == 0 || current->room->property == 0)
			{
				if (current->next->room->property == 1 && \
					current->next->space > 0)
				{
					printf("L%i-%s ", ant, current->room->name);
					current->next->space--;
					current->id = ant;
					current->space = ant++;
				}
				else if (current->next->room->property != 1 && \
					current->next->space != 0)
					ans_help(current);
			}
			current = current->next;
		}
		printf("\n");
	}
}
