/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:09:46 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/03 16:51:36 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bubble_algo_pt2(t_all *data, int round)
{
	while (round--)
	{
		RRA;
		write(1, "rra\n", 4);
	}
}

void		ft_bubble_algo(t_all *data)
{
	int		len;
	int		round;

	round = 0;
	len = ft_lstlen(data->lst_a);
	while (ft_are_sorted_a_val(data->lst_a) == 1)
	{
		if (AA > AB && AA != len - 1)
		{
			SA;
			write(1, "sa\n", 3);
			if (ft_are_sorted_a_val(data->lst_a) == 0)
				break ;
			if (round < len / 2)
				ft_bubble_algo_pt2(data, round);
			round = 0;
		}
		else
		{
			round++;
			RA;
			write(1, "ra\n", 3);
		}
	}
}
