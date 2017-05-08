/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:30 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 20:48:15 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdio.h>

typedef struct		s_data
{
	int				start;
	int				end;
	int				max_rooms;
	int				doc_size;
	int				max_links;
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

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

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

/*
** validation
*/

int					validate_doc(t_data data);
int					valid_ants(char *line);

/*
** validate_help
*/

int					valid_link(char *line);
int					valid_room(char *line);
int					valid_start_end(t_data data, char *keyword);

/*
** get_info
*/

char				*get_name(char *line);
void				get_max_rooms(t_data *data);
void				get_coord(char *line, t_coord *coord);

/*
** get_more_info
*/

int					get_id(t_data data, char *name);
int					check_id(t_data data, int i, int n);
void				get_start(t_data *data);
void				get_end(t_data *data);

/*
** init
*/

int					get_first_num(void);
void				get_doc(t_data *data);

/*
** get_rooms
*/

void				get_rooms(t_data *data);
void				get_max_rooms(t_data *data);
int					valid_room(char *line);
char				*get_name(char *line);

/*
** prep_rooms
*/

t_room				*link_rooms(t_room *rooms, t_data data);
t_room				*make_rooms(t_data data);
void				init_ants(t_links *head, int ants);

/*
** get_data
*/

t_data				get_data(void);
char				*get_link_num(char *link, int n);
int					check_id(t_data data, int i, int n);

/*
** get_links
*/

void				get_links(t_data *data);

/*
** get_map
*/

int					**make_map(t_data data);
int					**init_map(t_data data);

/*
** get_path
*/

t_links				*get_path(t_data data, t_room *rooms);
int					find_path(int *paths, int *used, t_data *data, int i);

/*
** let_it_go
*/

void				let_it_go(t_data *data, t_room *rooms, t_links *head);

/*
** print_ans
*/

void				print_ans(t_links *head, t_links *current,
						t_data data, int ant);

/*
** print_data
*/

void				print_data(t_data data, t_room *rooms, t_links *current);

#endif
