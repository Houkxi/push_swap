/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:55:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/01 18:17:34 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	nbr_of_cmds(t_all *data, int opt)
{
	int		i;
	t_moves	*tmp;

	i = 0;
	tmp = data->lst_move;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (opt & U)
		ft_printf("\nNomber of commands : %d for list size : %d\n", i,
		ft_lstlen(data->lst_a));
	else
		ft_printf("\nNomber of commands : %d\n", i);
}

void		opts_cmds(t_all *data, int opt)
{
	if (opt & V)
		nbr_of_cmds(data, opt);
	else if (opt & P || opt & B)
		ft_print_stack(data->lst_a);
}
