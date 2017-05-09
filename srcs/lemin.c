/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:09:31 by rle               #+#    #+#             */
/*   Updated: 2017/05/08 14:06:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_room	*rooms;
	t_links	*head;

	data = get_data();
	rooms = make_rooms(data);
	rooms = link_rooms(rooms, data);
	data.map = make_map(data);
	head = get_path(data, rooms);
	init_ants(head, data.ants);
	if (argc == 2)
		if (argv[1][0] == '-' && argv[1][1] == 'v')
			print_data(data, rooms, head);
	print_doc(data);
	print_ans(head, head, data, 1);
	let_it_go(&data, rooms, head);
}
