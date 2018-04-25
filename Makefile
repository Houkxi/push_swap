# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 12:47:15 by mmanley           #+#    #+#              #
#    Updated: 2018/04/25 14:01:17 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libswap.a

CC = gcc -o

CFLAGS = -Wall -Werror -Wextra

include chkr/make.dep
include pswp/make.dep
include srcs/make.dep

all : push check

push :
	$(CC) push_swap $(CFLAGS) -I ~/libft/includes -I ./includes $(PSRC) ~/libft/libft.a

check :
	$(CC) checker $(CFLAGS) -I ~/libft/includes -I ./includes $(SRCS) ~/libft/libft.a

clean :
	rm push_swap
	rm checker

re : clean all
