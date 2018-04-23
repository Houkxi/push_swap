/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:36:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/23 18:13:26 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*push_to_mid(t_lsts *l, int mid, int *ct, int grp)
{
	ft_printf("Mid : %d, L->mid : %d\n", mid, l->mid);
	while (l->mid-- > 0)
	{
		if (AA < mid)
		{
			l->a->grp = grp;
			PB;
			*ct += 1;
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

t_lsts		*quicksort_a(t_lsts *l, int size)
{
	int		pos;
	int		prtc = 0;

	while (is_sorted_incr(l->a, size) == 0 && prtc < size)
	{
		ft_lst_print_cir(&l->a, -1, -5);
		/*if (AA == find_min(l->a))
		{
			RA;
			ft_printf("ra\n");
		}*/
		pos = find_pos(l->a, l->a->data, 1, 1);
		ft_printf("%d, %d\n", pos, l->a->grp);

		if (pos < 0)
		{
			pos *= -1;
			while (pos-- && l->a->grp != 0)
			{
				if (is_sorted_incr(l->a, size) == 0)
				{
					RRA;
					ft_printf("rra\n");
					SA;
					ft_printf("sa\n");
				}
			}
		}
		else
		{
			while (pos-- && l->a->grp != 0)
			{
				SA;
				ft_printf("sa\n");
				if (is_sorted_incr(l->a, size) == 0)
				{
					RA;
					ft_printf("ra\n");
				}
			}
		}
		if (l->a->grp == 0 && is_sorted_incr(l->a, size) == 0)
		{
			RA;
			ft_printf("ra\n");
		}
		/*prtc++;
		if (prtc > 6)
			while(1);*/
	}
	if (is_sorted_incr(l->a, size) > 0)
	{
		while (size--)
			l->a->grp = 0;
		//PUT GROUPS TO 0;
	}
	return(l);
}
