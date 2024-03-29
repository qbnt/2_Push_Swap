# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 11:21:33 by qbanet            #+#    #+#              #
#    Updated: 2023/09/18 09:51:08 by qbanet           ###   ########.fr        #
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
SRC_DIR_SRCS = src/srcs

SRCS = parsing.c \
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
       error.c \
       read_instrucs.c \
       exec_instrucs.c \
       utiles.c

SRC_FILES_PUSH_SWAP = main.c

SRC_FILES_CHECKER = checker.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_FILES_PUSH_SWAP = $(OBJ) $(addprefix $(OBJ_DIR)/, $(SRC_FILES_PUSH_SWAP:.c=.o))
OBJ_FILES_CHECKER = $(OBJ) $(addprefix $(OBJ_DIR)/, $(SRC_FILES_CHECKER:.c=.o))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Emojis
CHECK = ✔️
ROCKET = 🚀

all: $(NAME_PUSH_SWAP)

$(OBJ_DIR)/%.o: $(SRC_DIR_SRCS)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

$(NAME_PUSH_SWAP): $(OBJ_FILES_PUSH_SWAP)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES_PUSH_SWAP) $(LIBFT) -o $(NAME_PUSH_SWAP)
	@echo "$(GREEN)$(ROCKET) Compilation de $(NAME_PUSH_SWAP) terminée avec succès ! $(ROCKET)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR_PUSH_SWAP)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_FILES_CHECKER)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES_CHECKER) $(LIBFT) -o $(NAME_CHECKER)
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

.PHONY: all clean fclean re bonus save
