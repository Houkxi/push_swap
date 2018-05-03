# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfavero <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:32:33 by cfavero           #+#    #+#              #
#    Updated: 2018/04/30 17:33:13 by cfavero          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME2 = checker

NAME = push_swap

FILEH = ./includes

C-SOURCES = files/ft_get_list.c\
			files/ft_print_stack.c \
			checks/ft_checker.c \
			files/functions.c \
			checks/main_checker.c\
			moves/ft_reverse.c\
			moves/ft_push.c\
			moves/ft_rotate.c\
			moves/ft_swap.c\
			files/options.c\
			files/options_file.c\
			# files/lst_moves.c

P-SOURCES = files/ft_get_list.c\
			files/ft_print_stack.c \
			push/push_swap.c\
			checks/ft_checker.c \
			files/functions.c \
			moves/ft_reverse.c\
			moves/ft_push.c\
			moves/ft_rotate.c\
			moves/ft_swap.c\
			push/main_push_swap.c\
			push/algorithm.c\
			files/options.c\
			files/options_file.c\
			# files/lst_moves.c

all: $(NAME)

$(NAME):
	@make -C ./printf
	@gcc -I $(FILEH) -o $(NAME2) $(C-SOURCES) ./printf/libftprintf.a
	@gcc -g3 -I $(FILEH) -o $(NAME) $(P-SOURCES) ./printf/libftprintf.a
	@make clean

clean:
	@make clean -C ./printf

fclean: clean
#	@make fclean -C ./printf
	@/bin/rm -f $(NAME) $(NAME2) ./printf/libftprintf.a

re: fclean all

.PHONY : all clean fclean re
