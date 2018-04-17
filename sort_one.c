/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:36:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 15:44:18 by mmanley          ###   ########.fr       */
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

t_lsts		*quick_sort_b(t_lsts *l)
{
	t_lst	*b;
	int		size;

	b = l->b;
	size = lst_ct_size(b);
	while (size--)
	{
		ft_lst_print_cir(&l->b, 1, -5);
		if (BA < BB)
		{
			SB;
			ft_printf("sb\n");
		}
		if (BA > BZ)
		{
			RB;
			ft_printf("rb\n");
		}
		else if (BZ > BA || BZ > BB)
		{
			/*if (BZ > BB)
				SB;*/
			RRB;
			ft_printf("~sb\nrrb\n");
		}
	}
	return (l);
}
