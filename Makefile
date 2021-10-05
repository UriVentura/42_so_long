# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oventura <oventura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 18:07:12 by oventura          #+#    #+#              #
#    Updated: 2021/10/05 17:51:42 by oventura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBMLX_DIR = ./mlx/
LIBMLX = libmlx.a

LIBFT_DIR = ./libft/
LIBFT = libft.a

INC = -I ./includes/

SRCS_DIR = ./srcs/
SRCS =	$(addprefix $(SRCS_DIR), fill.c \
		init.c \
		main.c \
		move.c \
		parse.c \
		utils.c \
		utils2.c )

OBJ = $(SRCS_DIR:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 $(INC)
LINKS = -lmlx -framework OpenGL -framework AppKit

# Regular Colors
BLACK='\033[0;30m'        # Black
RED='\033[0;31m'          # Red
GREEN='\033[0;32m'        # Green
YELLOW='\033[0;33m'       # Yellow
BLUE='\033[0;34m'         # Blue
PURPLE='\033[0;35m'       # Purple
CYAN='\033[0;36m'         # Cyan
WHITE='\033[0;37m'        # White

all: MAKE_LIBFT	MAKE_MLX $(NAME)

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
	@echo $(CYAN) "-----------------COMPILANDO $(NAME)-----------------" $(NONE)"
	@gcc $(CFLAGS) $(OBJ) $(LINKS) $(LIBMLX_DIR)$(LIBMLX) -o $(NAME)
	@gcc $(CFLAGS) $(OBJ) $(LINKS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
	@gcc $(CFLAGS) $(OBJ) $(LINKS) $(SRCS) -o $(NAME)
	@echo $(GREEN) "-----------------DONE-----------------" $(NONE)
	@rm $(OBJ)
	@echo $(RED) "-----------------DELETED OBJECT FILES-----------------" $(NONE)

$(OBJ): $(SRC)
	@echo $(GREEN) "     - Making object files..." $(NONE)
	@gcc $(CFLAGS) -c $(SRCS)

exe: all
	@echo $(CYAN) "-----------------EJECUTANDO $(NAME)-----------------" $(NONE)"
	@./$(NAME)
	@echo $(GREEN) "-----------------DONE-----------------" $(NONE)

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBMLX_DIR)
	@echo $(RED) "-----------------REMOVING OBJECT FILES-----------------" $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBMLX_DIR)
	@echo $(RED) "-----------------REMOVING $(NAME)-----------------" $(NONE)
	@rm -rf $(NAME)

re: fclean all