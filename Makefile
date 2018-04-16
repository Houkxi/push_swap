# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 12:47:15 by mmanley           #+#    #+#              #
#    Updated: 2018/04/16 09:28:45 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libswap.a

CC = gcc -o

CFLAGS = -Wall -Werror -Wextra

PSRCS = push_swap.c\
		data_pars.c\
		start_lst.c\
		find_mid.c\
		actions.c

push :
	$(CC) push_swap $(CFLAGS) $(PSRCS) ~/libft/libft.a -I ~/libft/includes

check :
	$(CC) checker $(CFLAGS) checker.c -I ~/libft/includes ~/libft/libft.a

clean :
	rm push_swap
	rm checker
