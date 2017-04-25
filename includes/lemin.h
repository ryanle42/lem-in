/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:30 by rle               #+#    #+#             */
/*   Updated: 2017/04/25 00:34:54 by rle              ###   ########.fr       */
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
	char			**rooms;
	char			**doc;
	char			**links;
	int				**map;
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
	int				dist;
	struct s_links	*links;
}					t_room;

typedef struct		s_links
{
	struct s_room	*room;
	struct s_links	*next;
}					t_links;

typedef struct 		s_path
{
	int				*path;
	int				size;
}					t_path;

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

// get data
t_data	get_data();

//get links
char **get_links(char **doc);

# endif