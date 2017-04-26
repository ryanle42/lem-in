/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:30 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 21:08:05 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"
#include <stdio.h>


typedef struct		s_data
{
	int				start; 
	int				end;
	int				max_rooms;
	int				ants;
	char			**rooms;
	char			**doc;
	char			**links;
	int				**map;
	int				pathsize;
}					t_data;

/*
** property
** 1 = start
** 0 = end
** 2 = normal
*/

typedef struct		s_room
{
	char			*name;
	int				property;
	int				ants;
	struct s_links	*links;
}					t_room;

typedef struct		s_links
{
	struct s_room	*room;
	struct s_links	*next;
	int				space;
	int				id;
}					t_links;

typedef struct		s_link
{
	char			*line;
	struct s_link	*next;
}					t_link;

// init
int		get_first_num();
char	**get_doc();


// get_rooms
char 	**get_rooms(char **doc);
int 	get_max_rooms(char **doc);
int		valid_room(char *line);
char	*get_name(char *line);

// get_data
t_data	get_data();
int		get_id(t_data data, char *name);
char *get_link_num(char *link, int n);

//get_links
char **get_links(char **doc);

//get_map
int **make_map(t_data data);
int **init_map(t_data data);

//get_path
t_links *get_path(t_data data, t_room *rooms);
int find_path(int *paths, int *used, t_data *data, int i);
# endif