# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oventura <oventura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 18:07:12 by oventura          #+#    #+#              #
#    Updated: 2021/10/02 14:53:42 by oventura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	fill.c \
		init.c \
		main.c \
		move.c \
		parse.c \
		utils.c \
		utils2.c

LIBFT_DIR = ./libft/
LIBFT = libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LINKS = -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: MAKE_LIBFT $(NAME)

MAKE_LIBFT:
	@echo "Compiling Libft..."
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	make fclean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all