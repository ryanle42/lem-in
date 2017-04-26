#include "lemin.h"

/*
**	INIT
*/

t_room *make_rooms(t_data data)
{
	t_room *rooms;
	int i;

	rooms = (t_room *)malloc(sizeof(t_room) * data.max_rooms);
	i = 0;
	while (data.rooms[i])
	{
		rooms[i].name = data.rooms[i];
		if (i == data.start)
			rooms[i].property = 1;
		else if (i == data.end)
			rooms[i].property = 0;
		else
			rooms[i].property = 2;
		rooms[i].ants = 0;
		rooms[i].links = (t_links *)malloc(sizeof(t_links));
		rooms[i].links->room = NULL;
		rooms[i].links->next = NULL;
		i++;
	}
	return (rooms);
}

t_room *link_rooms(t_room *rooms, t_data data)
{
	int i;
	int j;
	int k;

	t_links *current;
	i = 0;
	while (data.links[i])
	{
		j = get_id(data, get_link_num(data.links[i], 0));
		k = get_id(data, get_link_num(data.links[i], 1));
		current = rooms[j].links;
		if (!current->room)
			current->room = &rooms[k];
		else
		{
			while (current->next)
				current = current->next;
			current->next = (t_links *)malloc(sizeof(t_links));
			current->next->room = &rooms[k];
			current->next->next = NULL;
		}
		current = rooms[k].links;
		if (!current->room)
			current->room = &rooms[j];
		else
		{
			while (current->next)
				current = current->next;
			current->next = (t_links *)malloc(sizeof(t_links));
			current->next->room = &rooms[j];
			current->next->next = NULL;
		}
		i++;
	}
	return (rooms);
}

void init_ants(t_links *head, int ants)
{
	if (!head)
		return ;
	head->space = 0;
	head->id = 0;
	head->room->property = 0;
	while (head->next)
	{
		head = head->next;
		head->room->property = 2;
		head->id = 0;
		head->space = 0;
	}
	head->room->property = 1;
	head->space = ants;
}
void	print_ans(t_links *head, t_links *current, t_data data, int ant)
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
					current->space++;
					ant++;
				}
				else if (current->next->room->property != 1 && \
					current->next->space != 0)
				{
					printf("L%i-%s ", current->next->id, current->room->name);
					current->id = current->next->id;
					current->space++;
					current->next->space = 0;
				}
			}
			current = current->next;
		}
		printf("\n");
	}
}
void	print_data(t_data data, t_room *rooms, t_links *current)
{
	int i = 0;
	while (data.rooms[i])
	{
		printf("room:%s\n", data.rooms[i]);
		i++;
	}
	i = 0;
	while (data.links[i])
	{
		printf("link:%s\n", data.links[i]);
		i++;
	}
	printf("rooms:%i\n", data.max_rooms);
	printf("start: %s\n", data.rooms[data.start]);
	printf("end: %s\n", data.rooms[data.end]);
	printf("\n");
	i = 0;
	int j;
	printf("   ");
	while (i < data.max_rooms)
	{
		printf("%s ", data.rooms[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < data.max_rooms)
	{
		j = 0;
		printf("%s  ", data.rooms[i]);
		while (j < data.max_rooms)
		{
			printf("%i ", data.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	printf("\nid | name | links");
	while (i < data.max_rooms)
	{
		printf("\n\n%i    %s    ", get_id(data, rooms[i].name), rooms[i].name);
		if (rooms[i].links->room)
			printf(" %s", rooms[i].links->room->name);
		while (rooms[i].links->next)
		{
			rooms[i].links = rooms[i].links->next;
			printf(" %s", rooms[i].links->room->name);
		}
		i++;
	}
	printf("\n\npath:%s\n", current->room->name);
	while (current->next)
	{
		current = current->next;
		printf("path:%s\n", current->room->name);
	}
	printf("\n");
}

int main()
{
	t_data data;
	t_room *rooms;
	t_links *head;

	data = get_data();
	rooms = make_rooms(data);
	rooms = link_rooms(rooms, data);
	data.map = make_map(data);

	/*
	**	Print Data
	*/
	head = get_path(data, rooms);
	init_ants(head, data.ants);

	print_data(data, rooms, head);

	print_ans(head, head, data, 1);

}
