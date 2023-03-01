# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:28:31 by aben-nei          #+#    #+#              #
#    Updated: 2023/03/01 02:13:34 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast

# -fsanitize=address -g -Ofast
SRC = fdf.c utils.c parsine.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

# mv : libft/libft.a
# 	@mv libft/libft.a .

clean_libft:
	@make clean -C libft
clean:
	@rm -f $(OBJ)

fclean: clean
	# @make fclean -C libft
	@rm -f $(NAME) libft.a

re: fclean all
