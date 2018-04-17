/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:36:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 18:03:13 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*push_to_mid(t_lsts *l, int mid)
{
	while (l->mid-- > 0)
	{
		if (AA < mid)
		{
			PB;
			ft_printf("pb\n");
		}
		else
		{
			RA;
			ft_printf("ra\n");
		}
	}
	return (l);
}

int			find_min(t_lst *lst)
{
	t_lst	*tmp;
	int		tp;

	tp = 2147483647;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data <= tp)
			tp = tmp->data;
		tmp = tmp->next;
	}
	if (tmp->data <= tp)
		tp = tmp->data;
	return (tp);
}

int			find_max(t_lst *lst)
{
	t_lst	*tmp;
	int		tp;

	tp = -2147483648;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data >= tp)
			tp = tmp->data;
		tmp = tmp->next;
	}
	if (tmp->data <= tp)
		tp = tmp->data;
	return (tp);
}

t_lsts		*quick_sort_b(t_lsts *l)
{
	t_lst	*b;
	int		size;
	int		size2;
	int		mid;
	int		mid2;
	int		min;
	int		max;

	b = l->b;
	size = lst_ct_size(b);
	mid = find_mid(b, size);
	mid2 = 15;
	size2 = size;
	min = find_min(l->b);
	max = find_max(l->b);
	ft_printf("B mid = %d, Size = %d, min = %d\n", mid, size, min);
	while (size2--)
	{
		//ft_lst_print_cir(&l->b, 1, -5);
		/*if (max == BA && BB != min)
		{
			while (max == BA && BB != min)
			{
				SB;
				RB;
				ft_printf("sb, rb\n");
			}
		}*/

		/*
			Creaye a IS SORTED for the 3 first (prev, curr, next)
			if it is sorted RB and see the 3 new ones
			TESTING PHASE
		*/
		if (size >= 3)
		{
			if (BA > mid)
			{
				if (BA > BB && BB != min)
					SB;
				ft_printf("sb\n");
			}
			else if (BA <= mid && BZ <= mid)
			{
				RB;
				ft_printf("rb\n");
			}
			else if (BZ > mid)
			{
				RRB;
				ft_printf("rrb\n");
			}
		}
		else if (BA < BB)
		{
			size2 = 0;
			ft_printf("rb\n");
		}
		/*mid2--;
		if (mid2 == 0)
			while (1);*/
	}
	return (l);
}

t_lsts		*quick_sort_a(t_lsts *l)
{
	t_lst	*a;
	int		max;
	int		size;

	a = l->a;
	max = find_max(a);
	size = lst_ct_size(a);
	while ((ft_is_sorted_other_side(a, size)) == 0 && size--)
	{
		ft_lst_print_cir(&l->a, -1, -5);
		if (AZ < AA && AA != max)
		{
			RRA;
			ft_printf("rra\n");
		}
		if (AA > AB)
		{
			RA;
			ft_printf("ra\n");
		}
		else
		{
			SA;
			ft_printf("sa\n");
		}
	}
	return (l);
}
