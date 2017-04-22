/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:30 by rle               #+#    #+#             */
/*   Updated: 2017/04/21 14:22:29 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"
#include <stdio.h>


typedef struct		s_data
{
	int				ants;
	int				start; 
	int				end;
	int				rooms;
}					t_data;

typedef struct		s_link
{
	char 			*line;
	struct s_link	*next;
}					t_link;

typedef struct 		s_doc
{
	char			**file;
	int				size;
}					t_doc;

// init
int		get_first_num();
char	**get_doc();


// get_rooms
char 	**get_rooms(char **doc);
int 	get_max_rooms(char **doc);
int	valid_room(char *line);
char	*get_name(char *line);

# endif