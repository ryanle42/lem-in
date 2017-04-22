#include "lemin.h"

/*
**	INIT
*/

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

int link_num(char *link, int n)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (link[i] && ft_isdigit(link[i]))
	{
		num *= 10;
		num += link[i] - '0';
		i++;
	}
	if (n == 0)
		return (num);
	num = 0;
	i++;
	while (link[i] && ft_isdigit(link[i]))
	{
		num *= 10;
		num += link[i] - '0';
		i++;
	}
	return (num);
}
int **make_map(t_data data)
{
	int **map;
	int i;

	map = init_map(data);
	i = 0;
	while (data.links[i])
	{
		map[link_num(data.links[i], 0)][link_num(data.links[i], 1)] = 1;
		map[link_num(data.links[i], 1)][link_num(data.links[i], 0)] = 1;
		i++;
	}
	return (map);
}

int main()
{
	t_data data;
	int	**map;

	data = get_data();
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
}
