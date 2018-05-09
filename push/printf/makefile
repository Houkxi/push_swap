# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfavero <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:32:33 by cfavero           #+#    #+#              #
#    Updated: 2018/03/18 19:08:00 by cfavero          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILEH = libft.h ft_printf.h

SOURCES-PRF = flag_c.c flag_d.c flag_s.c flag_u.c ft_fillstruct.c ft_printf.c \
	get_list.c  ft_precision_d.c ft_unicode.c flag_o.c ft_size_d.c \
	ft_itoa_base.c ft_precision_x.c ft_size_u.c flag_x.c ft_uitoa_base.c

OBJECTS-PRF = $(SOURCES-PRF:.c=.o)

ESE = ./a.out

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -I $(FILEH) -c -Wall -Wextra -Werror $(SOURCES-PRF)
	@libtool -static -o $@ libft/libft.a $(OBJECTS-PRF)
	@ranlib $(NAME)

clean:
	@make clean -C ./libft
	@/bin/rm -f $(OBJECTS-PRF)

fclean: clean
	@/bin/rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY : all clean fclean re
