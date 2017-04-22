#include "lemin.h"

/*
**	INIT
*/

int get_start(char **doc)
{
	int i;
	int room;

	room = 0;
	i = 0;
	while (doc[i])
	{
		if (!ft_strcmp("##start", doc[i]))
			return (room);
		if (valid_room(doc[i]))
			room++;
		i++;
	}
	return (-1);
}

int get_end(char **doc)
{
	int i;
	int room;

	room = 0;
	i = 0;
	while (doc[i])
	{
		if (!ft_strcmp("##end", doc[i]))
			return (room);
		if (valid_room(doc[i]))
			room++;
		i++;
	}
	return (-1);
}

int main()
{
	char **doc;
	int start;
	int end;

	doc = get_doc();

	char **rooms;


	rooms = get_rooms(doc);

	if ((start = get_start(doc)) < 0)
		printf("error\n");
	if ((end = get_end(doc)) < 0)
		printf("error\n");
	int i = 0;
	while (rooms[i])
	{
		printf("room:%s\n", rooms[i]);
		i++;
	}
	printf("start: %i\n", start);
	printf("end: %i\n", end);

}
