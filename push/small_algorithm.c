/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:09:46 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/09 16:26:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_random_3(t_all *data)
{
	long	i;

	i = 1000000000 / 2;
	while (i)
		i--;
	ft_printf("0\033[H\033[2J");
	ft_print_2stack(data->lst_a, data->lst_b);
}

int			ft_random_4(int *arr, int ch)
{
	free(arr);
	return (ch);
}

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
