# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 22:15:20 by adbouras          #+#    #+#              #
#    Updated: 2024/04/24 18:57:07 by adbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[1;92m'
YELLOW = '\033[0;93m'
DEF_COLOR = '\033[0;39m'

CC = cc

NAME = push_swap

BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c list_utils.c rev_rotate.c push_oper.c rotate_oper.c \
	swap_oper.c push_swap_utils.c ft_inserion.c swap_push_utils.c free_opera.c \

MAIN = main.c \

BNS_SRC = ./bonus/checker.c \
	./bonus/get_next_line/get_next_line.c \
	./bonus/get_next_line/get_next_line_utils.c \

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

$(NAME): $(SRC) $(MAIN)
	@echo $(YELLOW)"\n____________________ Compiling Libft ____________________\n"$(DEF_COLOR)
	@make -C libft
	@make bonus -C libft
	@echo $(GREEN)"\n____________________ Compiled Libft ____________________\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n__________________ Compiling ft_printf __________________\n"$(DEF_COLOR)
	@make -C ft_printf
	@echo $(GREEN)"\n__________________ Compiled ft_printf __________________\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n__________________ Compiling push_swap __________________\n"$(DEF_COLOR)
	$(CC) $(CFLAGS) $(SRC) $(MAIN) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo $(GREEN)"\n__________________ Compiled push_swap __________________\n"$(DEF_COLOR)

$(BONUS): $(BNS_SRC) $(LIBFT) $(PRINTF)
	@echo $(YELLOW)"\n____________________ Compiling Bonus ____________________\n"$(DEF_COLOR)
	$(CC) $(CFLAGS) $(SRC) $(BNS_SRC) $(LIBFT) $(PRINTF) -o $(BONUS)
	@echo $(GREEN)"\n____________________ Compiled Bonus ____________________\n"$(DEF_COLOR)

all: $(NAME)

bonus: $(BONUS)
	
clean:
	@make clean -C libft
	@make clean -C ft_printf

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(BONUS)

re:	fclean all