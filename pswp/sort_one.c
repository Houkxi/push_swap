/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:36:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/24 17:00:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*push_to_mid(t_lsts *l, int mid, int *ct, int *grp)
{

	ft_printf("\n***************PUSHING TO MID %d***********\n", *grp);
	ft_printf("Mid : %d, L->mid : %d\n", mid, l->mid);
	while (mid > find_min(l->a) && grp_len(l->a, 0) != lst_len(l->a))
	{
		if (AA < mid && l->a->grp != 0)
		{
			l->a->grp = *grp;
			PB;
			*ct -= 1;
			ft_printf("pb\n");
		}
		else
		{
			RA;
			ft_printf("ra\n");
		}
	}
	*grp += 1;
	ft_printf("ct %d\n", *ct);
	return (l);
}

t_lsts		*quicksort_a(t_lsts *l, int size)
{
	int		pos;
	int		prtc = 0;

	while (is_sorted_incr(l->a, size) == 0 && prtc < size)
	{
		/*if (AA == find_min(l->a))
		{
			RA;
			ft_printf("ra\n");
		}*/
		//ft_printf("%d, %d\n", pos, l->a->grp);
		pos = find_pos(l->a, l->a->data, 1, 1);
		//ft_lst_print_cir(&l->a, -1, -5);
		//ft_printf("%d, %d\n", pos, l->a->grp);
		if (AA == find_max(l->a))
		{
			RA;
			ft_printf("TEST OF THIS SHIT ra\n");
			l->a->prev->grp = 0;
		}
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
			/*if (AA > AZ)
			{
				RRA;
				ft_printf("rra\n");
			}*/
		}
		else
		{
			//ft_printf("test\n");
			while (pos-- && l->a->grp != 0)
			{
				//ft_printf("POS : %d\n", pos);
				SA;
				ft_printf("sa\n");
				if (is_sorted_incr(l->a, size) == 0)
				{
					RA;
					ft_printf("ra\n");
				}
			}
			if (AA > AZ)
			{
				RRA;
				ft_printf("rra\n");
			}
		}
		/*if (l->a->grp == 0 && is_sorted_incr(l->a, size) == 0)
		{
			RA;
			ft_printf("ra\n");
		}*/
		prtc++;
		/*if (prtc > 6)
			while(1);*/
	}
	/*if (is_sorted_incr(l->a, size) > 0)
	{
		while (size--)
			l->a->grp = 0;
		//PUT GROUPS TO 0;
	}*/
	return(l);
}
