/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:36:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/27 19:44:04 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_solve_a(t_lsts *l)
{
	int	moves;

	moves = 0;
	while (ft_are_sorted_a(l->a) == 1)
	{
		if (AA > AB )
		{
			SA;
			ft_printf("sa\n");
		}
		else
		{
			RA;
			ft_printf("ra\n");
			if (AA > AB )
			{
				SA;
				ft_printf("sa\n");
			}
			RRA;
			ft_printf("rra\n");
		}
	}
	return (0);
}

// we use it

int		ft_move_on_a(t_lsts *l, int middle, int *max)
{
	int	moves;
	int	back;

	moves = 0;
	back = 0;
	while ((moves + back) < *max)
	{
		if (BA > middle)
		{
			PA;
			ft_printf("pa\n");
			moves++;
		}
		else
		{
			RB;
			ft_printf("rb\n");
			back++;
		}
	}
	*max = back;
	while (back--)
	{
		RRB;
		ft_printf("rrb\n");
	}
	return (moves);
}

// we use it

int		ft_move_on_b(t_lsts *l, int middle, int max)
{
	int	moves;
	int	back;

	moves = 0;
	back = 0;
	while (moves < max)
	{
		if (AA <= middle)
		{
			PB;
			ft_printf("pb\n");
			moves++;
		}
			else
		{
			RA;
			ft_printf("ra\n");
			back++;
		}
	}
	while (back--)
	{
		RRA;
		ft_printf("rra\n");
	}
	return (moves);
}
