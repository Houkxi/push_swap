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

int		ft_solve_a(t_all *data)
{
	int	moves;

	moves = 0;
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
			RA;
			write(1, "ra\n", 3);
			if (AA > AB )
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
	}
	return (0);
}

int		ft_move_on_a(t_all *data, int middle, int *max)
{
	int	moves;
	int	back;

	moves = 0;
	back = 0;
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

int		ft_move_on_b(t_all *data, int middle, int max, int elem)
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

int		loop_spot(t_lst *a, int sv)
{
	t_lst	*tmp;
	int	x;

	x = 0;
	tmp = a;
	while (tmp->next != a)
	{
		if (sv > tmp->exval)
			x++;
		tmp = tmp->next;
	}
	if (sv > tmp->exval)
		x++;
	return (x);
}

t_lst	*change_lst(t_lst *a)
{
	t_lst       *tmp2;
	int         sv;
	int         x;

	tmp2 = a;
	x = 0;
	while (tmp2->next != a)
	{
		sv = tmp2->exval;
		x = loop_spot(a, sv);
		tmp2->val = x;
		tmp2 = tmp2->next;
	}
	sv = tmp2->exval;
	x = loop_spot(a, sv);
	tmp2->val = x;
	return (tmp2);
}
