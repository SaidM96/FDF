# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smia <smia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:38:08 by smia              #+#    #+#              #
#    Updated: 2022/02/08 02:00:36 by smia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CSRCS= fdf.c ft_atoi.c ft_split.c ft_draw.c get_next_line.c read_map.c  get_next_line_utils.c operations.c hex_to_dec.c handle_colored_map.c get_map_width.c
CFLAGS= -Wall -Wextra -Werror
CC= gcc

OBJS=$(CSRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $^

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all