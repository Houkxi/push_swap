/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:55:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/07 20:14:03 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	color_choices(char *s1)
{
	if (ft_strcmp("ra\n", s1) == 0)
		write(1, "\x1B[32m", 5);
	else if (ft_strcmp("rb\n", s1) == 0)
		write(1, "\x1B[32m", 5);
	else if (ft_strcmp("pa\n", s1) == 0)
		write(1, "\x1B[35m", 5);
	else if (ft_strcmp("pb\n", s1) == 0)
		write(1, "\x1B[31m", 5);
	else if (ft_strcmp("sa\n", s1) == 0)
		write(1, "\x1B[33m", 5);
	else if (ft_strcmp("sb\n", s1) == 0)
		write(1, "\x1B[33m", 5);
	else if (ft_strcmp("rra\n", s1) == 0)
		write(1, "\x1B[34m", 5);
	else if (ft_strcmp("rrb\n", s1) == 0)
		write(1, "\x1B[36m", 5);
	else if (ft_strcmp("ss\n", s1) == 0)
		write(1, "\x1B[31m", 5);
	else if (ft_strcmp("rr\n", s1) == 0)
		write(1, "\x1B[31m", 5);
	else if (ft_strcmp("rrr\n", s1) == 0)
		write(1, "\x1B[31m", 5);
}

static void	nbr_of_cmds(t_all *data, int opt)
{
	if (opt & U)
		ft_printf("Nomber of commands : %d for list size : %d\n", data->moves,
		ft_lstlen(data->lst_a));
	else
		ft_printf("Nomber of commands : %d\n", data->moves);
}

void		opts_cmds(t_all *data, int opt)
{
	if (opt & V)
		nbr_of_cmds(data, opt);
	else if (opt & P || opt & B)
		ft_print_stack(data->lst_a, 'A');
}
