# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 11:21:33 by qbanet            #+#    #+#              #
#    Updated: 2023/09/17 11:17:34 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)/includes

SRC_DIR_PUSH_SWAP = src/push_swap
SRC_DIR_CHECKER = src/checker

SRC_FILES_PUSH_SWAP =	main.c\
						parsing.c\
						moves.c \
						accio.c \
						push_swap.c \
						algo_3.c \
						algo_5.c \
						turk_algo.c \
						turk_algo_utiles.c \
						utiles_1.c \
						utiles_2.c \
						utiles_3.c \
						error.c

SRC_FILES_CHECKER =		main.c \
						read_instrucs.c \
						exec_instrucs.c \
						utiles.c

SRC_PUSH_SWAP = $(addprefix $(SRC_DIR_PUSH_SWAP)/, $(SRC_FILES_PUSH_SWAP))
SRC_CHECKER = $(addprefix $(SRC_DIR_CHECKER)/, $(SRC_FILES_CHECKER))

OBJ_DIR = obj
OBJ_FILES_PUSH_SWAP = $(SRC_FILES_PUSH_SWAP:.c=.o)
OBJ_FILES_CHECKER = $(SRC_FILES_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES_PUSH_SWAP))
OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES_CHECKER))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Emojis
CHECK = ✔️
ROCKET = 🚀

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(LIBFT) -o $(NAME_PUSH_SWAP)
	@echo "$(GREEN)$(ROCKET) Compilation de $(NAME_PUSH_SWAP) terminée avec succès ! $(ROCKET)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR_PUSH_SWAP)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_CHECKER)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(NAME_CHECKER)
	@echo "$(GREEN)$(ROCKET) Compilation de $(NAME_CHECKER) terminée avec succès ! $(ROCKET)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR_CHECKER)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(CHECK) Nettoyage des fichiers objets terminé$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_PUSH_SWAP) $(NAME_CHECKER)
	@echo "$(GREEN)$(CHECK) Nettoyage complet terminé$(RESET)"

save: fclean
	git add .
	git commit -m "make save"
	git push

re: fclean all

.PHONY: all clean fclean re bonus
