# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:29:53 by rle               #+#    #+#              #
#    Updated: 2017/05/07 21:35:34 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

OBJS = $(addprefix ./srcs/, \
			$(addsuffix .o, \
				lemin \
				init \
				get_rooms \
				prep_rooms \
				get_data \
				print_data \
				get_links \
				get_map \
				validation \
				validate_help \
				get_path \
				let_it_go \
				print_ans \
				get_info \
				get_more_info \
			) \
		)

CFLAGS = -Wall -Werror -Wextra

CC = @gcc

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(LIB)/libft.a $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "\x1B[31m./lemin made"
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB): force
	@make -C libft

force: 
	@true

clean:
	@rm -f $(OBJS)
	@echo "\x1B[34m~~~clean~~~"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
