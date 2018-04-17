# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 12:47:15 by mmanley           #+#    #+#              #
#    Updated: 2018/04/17 14:40:06 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libswap.a

CC = gcc -o

CFLAGS = -Wall -Werror -Wextra

PSRCS = checker.c\
		data_pars.c\
		start_lst.c\
		find_mid.c\
		a_list_acts.c\
		b_list_acts.c\
		sort_one.c\

push :
	$(CC) push_swap $(CFLAGS) $(PSRCS) ~/libft/libft.a -I ~/libft/includes

check :
	$(CC) checker $(CFLAGS) $(PSRCS) -I ~/libft/includes ~/libft/libft.a

clean :
	rm push_swap
	rm checker
