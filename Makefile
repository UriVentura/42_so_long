# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oventura <oventura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 18:07:12 by oventura          #+#    #+#              #
#    Updated: 2021/10/05 19:53:56 by oventura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBMLX_DIR = ./mlx/
LIBMLX = libmlx.a

LIBFT_DIR = ./libft/
LIBFT = libft.a

INC = -I ./includes/
INC_MLX = -I ./mlx/
INC_LIBFT = -I ./libft/

SRCS_DIR = ./srcs/
SRCS =	$(addprefix $(SRCS_DIR), fill.c \
		init.c \
		main.c \
		move.c \
		parse.c \
		utils.c \
		utils2.c )

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 $(INC) $(INC_MLX) $(INC_LIBFT)
LINKS = -lmlx -framework OpenGL -framework AppKit

# REGULAR COLORS
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

all: MAKE_LIBFT	MAKE_MLX $(SRCS) $(NAME)

MAKE_MLX:
	@echo $(RED) "-----------------COMPILING $(NAME)-----------------" $(NONE)
	@echo $(CYAN) "Compiling Mlx..." $(NONE)
	@echo $(RED) "-----------------COMPILING $(NAME)-----------------" $(NONE)
	@echo $(CYAN) "Compiling Mlx...100%" $(NONE)
	@make -C $(LIBMLX_DIR)
MAKE_LIBFT:
	@echo $(RED) "-----------------COMPILING $(NAME)-----------------" $(NONE)
	@echo $(CYAN) "Compiling LIBFT..." $(NONE)
	@echo $(RED) "-----------------COMPILING $(NAME)-----------------" $(NONE)
	@echo $(CYAN) "Compiling LIBFT...100%" $(NONE)
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@echo $(CYAN) "-----------------COMPILANDO $(NAME)-----------------" $(NONE)
	@gcc $(CFLAGS) $(OBJ) $(LIBMLX_DIR)$(LIBMLX) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
	@echo $(GREEN) "-----------------DONE-----------------" $(NONE)
	@rm $(OBJ)
	@echo $(RED) "-----------------DELETED OBJECT FILES-----------------" $(NONE)

%.o: %.c
	@gcc $(INC) $(INC_LIBFT) $(INC_MLX) -o $@ -c $^

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)
	@echo $(RED) "-----------------REMOVING OBJECT FILES-----------------" $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBMLX_DIR)
	@echo $(RED) "-----------------REMOVING $(NAME)-----------------" $(NONE)
	@rm -rf $(NAME)

re: clean fclean all