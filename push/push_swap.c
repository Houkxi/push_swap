/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:26:08 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/03 12:04:09 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_solve_a_pt2(t_all *data)
{
	RA;
	write(1, "ra\n", 3);
	if (AA > AB)
	{
		if (AA > AB && data->lst_b && data->lst_b->next && BA < BB)
		{
			SS;
			write(1, "ss\n", 3);
		}
		else
		{
			SA;
			write(1, "sa\n", 3);
		}
	}
	RRA;
	write(1, "rra\n", 4);
}

int				ft_solve_a(t_all *data)
{
	while (ft_are_sorted_a_val(data->lst_a) == 1)
	{
		if (AA > AB)
		{
			if (AA > AB && data->lst_b && data->lst_b->next && BA < BB)
			{
				SS;
				write(1, "ss\n", 3);
			}
			else
			{
				SA;
				write(1, "sa\n", 3);
			}
		}
		else
		{
			ft_solve_a_pt2(data);
		}
	}
	return (0);
}

int				ft_move_on_a(t_all *data, int middle, int *max, int back)
{
	int	moves;

	moves = 0;
	while (data->lst_b && (moves + back) < *max)
	{
		if (BA > middle)
		{
			PA;
			write(1, "pa\n", 3);
			moves++;
		}
		else
		{
			RB;
			write(1, "rb\n", 3);
			back++;
		}
	}
	*max = back;
	while (back--)
	{
		RRB;
		write(1, "rrb\n", 4);
	}
	return (moves);
}

int				ft_move_on_b(t_all *data, int middle, int max, int back)
{
	int	moves;

	moves = 0;
	while (moves < max)
	{
		if (AA <= middle)
		{
			PB;
			write(1, "pb\n", 3);
			moves++;
		}
		else
		{
			RA;
			write(1, "ra\n", 3);
			back++;
		}
	}
	while (back-- && data->round == 1)
	{
		RRA;
		write(1, "rra\n", 4);
	}
	return (moves);
}
