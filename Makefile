# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:29:53 by rle               #+#    #+#              #
#    Updated: 2017/04/25 20:02:34 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

OBJS = $(addsuffix .o, lem-in init get_rooms get_data get_links get_map \
		get_path)

CC = gcc

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(LIB)/libft.a $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	gcc -c $< $(INCLUDES)

$(LIB): force
	$(MAKE) -C libft

force: 
	@true

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
