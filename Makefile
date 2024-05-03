# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 22:15:20 by adbouras          #+#    #+#              #
#    Updated: 2024/05/02 18:37:00 by adbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[1;92m'
YELLOW = '\033[0;93m'
RED='\033[1;91m'
DEF_COLOR = '\033[0;39m'

CC = cc

NAME = push_swap

BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c list_utils.c rev_rotate.c push_oper.c rotate_oper.c \
	swap_oper.c push_swap_utils.c ft_inserion.c swap_push_utils.c free_opera.c \

OBJ = $(SRC:.c=.o)

MAIN = main.c \

MAIN_OBJ = $(MAIN:.c=.o)

BNS_SRC = ./checker_bonus/checker_bonus.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

BOBJECT = $(BNS_SRC:.c=.o)

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a


$(NAME): $(OBJ) $(MAIN_OBJ)
	@echo $(YELLOW)"\n░░░░░░░ Compiling Libft ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	make -C libft
	make bonus -C libft
	@echo $(GREEN) "\n░░░░░░░░ Libft Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n░░░░░░░░ Compiling ft_printf ░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	make -C ft_printf
	@echo $(GREEN) "\n░░░░░░░░ ft_printf Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n░░░░░░░░ Compiling push_swap ░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo $(GREEN) "\n░░░░░░░░ push_swap Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)

$(BONUS): $(OBJ) $(BOBJECT)
	@echo $(YELLOW)"\n░░░░░░░░ Compiling Libft ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	make -C libft
	make bonus -C libft
	@echo $(GREEN) "\n░░░░░░░░ Libft Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n░░░░░░░░ Compiling ft_printf ░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	make -C ft_printf
	@echo $(GREEN) "\n░░░░░░░░ ft_printf Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	@echo $(YELLOW)"\n░░░░░░░░ Compiling Bonus ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)
	$(CC) $(CFLAGS) $(OBJ) $(BOBJECT) $(LIBFT) $(PRINTF) -o $(BONUS)
	@echo $(GREEN) "\n░░░░░░░░ Bonus Compiled ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)

all: $(NAME)

bonus: $(BONUS)
	
clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	rm -f $(BOBJECT)
	@echo $(RED)   "\n░░░░░░░░ Objects Cleaned ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)
	rm -f $(BONUS)
	@echo $(RED)   "\n░░░░░░░░ EXE Cleaned ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"$(DEF_COLOR)

re:	fclean all
