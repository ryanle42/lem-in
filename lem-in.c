#include "lemin.h"

/*
**	INIT
*/


int		get_id(t_data data, char *name)
{
	int i;

	i = 0;
	while (data.rooms[i])
	{
		if (!ft_strcmp(data.rooms[i], name))
			return (i);
		i++;
	}
	return (-1);
}

int **init_map(t_data data)
{
	int **map;
	int x;
	int y;

	map = (int **)malloc(sizeof(int*) * data.max_rooms);
	y = 0;
	while (y < data.max_rooms)
	{
		map[y] = (int *)malloc(sizeof(int) * data.max_rooms);
		x = 0;
		while (x < data.max_rooms)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

char *link_num(char *link, int n)
{
	int i;
	int j;
	char *c;

	i = 0;
	while (link[i] != '-')
		i++;
	c = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (link[i] != '-')
	{
		c[i] = link[i];
		i++;
	}
	c[i] = '\0';
	if (n == 0)
		return (c);
	free(c);
	i++;
	j = 0;
	while (link[i + j])
		j++;
	c = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (link[i])
	{
		c[j] = link[i];
		j++;
		i++;
	}
	c[j] = '\0';
	return (c);
}

int **make_map(t_data data)
{
	int **map;
	int i;
	int y;
	int x;

	map = init_map(data);
	i = 0;
	while (data.links[i])
	{
		y = get_id(data, link_num(data.links[i], 0));
		x = get_id(data, link_num(data.links[i], 1));
		map[y][x] = 1;
		map[y][x] = 1;
		i++;
	}
	return (map);
}

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
		rooms[i].dist = -1;
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
		j = get_id(data, link_num(data.links[i], 0));
		k = get_id(data, link_num(data.links[i], 1));
		printf("rm: %i link :%i\n ", j, k);
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

void	recursion(t_links *link, int i)
{
	if (!link || !link->room)
		return ;
	if (link->room->dist != -1)
		return ;
	link->room->dist = i;
	recursion(link->room->links, i + 1);
	while (link->next)
	{
		link = link->next;
		recursion(link, i + 1);
	}
}

int main()
{
	t_data data;
	t_room *rooms;
	int	**map;

	data = get_data();
	rooms = make_rooms(data);
	rooms = link_rooms(rooms, data);
	map = make_map(data);

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
	printf("start: %i\n", data.start);
	printf("end: %i\n", data.end);
	printf("\n");
	i = 0;
	int j;
	while (i < data.max_rooms)
	{
		j = 0;
		while (j < data.max_rooms)
		{
			printf("%i ", map[i][j]);
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

	rooms[data.end].dist = 0;
	recursion(rooms[data.end].links, 1);
	i = 0;
	while (i < data.max_rooms)
	{
		printf("\nroom: %s dist: %i", rooms[i].name, rooms[i].dist);
		i++;
	}
}
