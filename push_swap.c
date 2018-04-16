/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/16 13:17:34 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			string_check(int av, char **ac, int ch)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < av)
	{
		while (ac[y][x])
		{
			if ((ch = ft_occ_pos("-0123456789 ", ac[y][x])) == -1 ||
			(ac[y][x] == '-' && ((ac[y][x - 1] != ' ' && x != 0) ||
			ft_isdigit(ac[y][x + 1]) == 0)))
			{
				ft_printf("_%c_\nError, %3d\n", ac[y][x], ch);
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

t_lst		*push_swaping(t_lst *la, int mid, int size)
{
	t_lst	*lb;
	t_lsts	*l;

	if (!(l = (t_lsts*)malloc(sizeof(t_lsts))))
		return (NULL);
	lb = NULL;
	l->a = la;
	size = 0;
	ft_lst_print_cir(&la, -1, 5);
	while (la->next != l->a)
	{
		if (la->data <= mid)
		{
			PB;
			ft_printf("pb\n");
			la = l->a;
			lb = l->b;
		}
		else
			la = la->next;
	}
	ft_lst_print_cir(&la, -1, -5);
	ft_lst_print_cir(&lb, 1, -5);
	return (la);
}

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lst	*tmp;
	int		ct;

	ct = 1;
	if (av < 2)
		return (0);
	if ((string_check(av - 1, &ac[1], 0)) == -1)
	{
		ft_printf("BASIC PROBLEMS\n");
		return (-1);
	}
	if (!(lst = init_pars(&ac[1], av - 1)))
	{
		ft_printf("PROBLEME WITH DATA PARS\n");
		return (-1);
	}
	tmp = lst;
	while (tmp->next != lst)
	{
		tmp = tmp->next;
		ct++;
	}
	tmp = find_mid(lst, ct);
	ft_printf("MID = %d ---> Size = %d\n", tmp->data, ct);
	if (!(tmp = push_swaping(lst, tmp->data, ct)))
		return (-1);
	return (0);
}
