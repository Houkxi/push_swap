/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/23 18:52:51 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			string_check(int av, char **ac, int ch)
{
	int		x;
	int		y;

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

int			checker(int mid, int size, t_lsts *l, int grp, int ct, int newct)
{
	int		ct2;

	while (is_sorted_incr(l->a, l->mid) == 0)
	{
		//if (newct == 3)
		check_grps(l);
		ft_printf("new = %d, size = %d, l->mid : %d,  sorted : %d, ct = %d\n", newct, size, l->mid, is_sorted_incr(l->a, size), ct);
		ft_lst_print_cir(&l->a, -1, 5);
		if (l->mid > 3 && is_sorted_incr(l->a, l->mid) == 0)
		{
			ft_printf("1\n");
			mid = find_mid(l->a, l->mid);
			push_to_mid(l, mid, &ct, grp);
			grp++;
			l->mid = lst_len(l->a);
			newct++;
			ft_lst_print_cir(&l->a, -1, 5);
			if ((checker(mid, size, l, grp + 1, ct, newct)))
			{
				ft_printf("END\n");
				return (-1);
			}
		}
		if (is_sorted_incr(l->a, l->mid) > 0)
		{
			ft_printf("2\n");
			ct2 = ct;
			while (ct-- >= ct2 / 2 && l->b != NULL)
			{
				PA;
				ft_printf("pa\n");
				newct++;
			}
			ct = lst_len(l->b);
			l->mid = lst_len(l->a);
		}
		else
		{
			ft_printf("3\n");
			l = quicksort_a(l, ct);
		}
		ft_lst_print_cir(&l->b, 1, 5);
	}
	ft_printf("TESTING\n");
	if (is_sorted_incr(l->a, size) > 0 && l->b == NULL)
		return (-1);
	else
	{
		ft_printf("return (0)\n");
		return (0);
	}
}
/*
t_lsts		*checker(int mid, int size, t_lsts *l, int grp, int ct, int newct)
{
	int		ct2;

	if (ct != 3)
	{
		ft_printf("%d\n", ct);
		ft_printf("SIZE 3 TEST\n");
		l = quicksort_a(l, ct);
		ft_lst_print_cir(&l->a, -1, -5);
		//while (1);
	}
	if (is_sorted_incr(l->a, size) == 0 && size >= 3)
	{
		mid = find_mid(l->a, size);
		l->mid = size;
		//newct--;
		push_to_mid(l, mid, &ct, grp);
		ft_printf("MID : %d, CT : %d, GRP : %d, NWCT : %d\n", mid, ct, grp, newct);
		ft_lst_print_cir(&l->a, -1, 5);
		ft_lst_print_cir(&l->b, 1, 5);
	}
	else if (size >= 3 && is_sorted_incr(l->a, size) > 0)
	{
		ct2 = ct;
		ft_printf("1ct = %d\n", ct);
		while (ct-- >= ct2 / 2&& ct > 0 && l->b != NULL)
		{
			PA;
			ft_printf("pa\n");
			newct++;
		}
		ft_printf("2ct = %d\n", ct);
		if (ct == 0)
			ct = lst_len(l->b);
		mid = find_mid(l->a, newct);
		newct = 0;
		ft_printf("NEW MID : %d\n", mid);
		ft_lst_print_cir(&l->a, -1, 5);
		//while(1);
	}
	//ft_printf("SORTED : %d, %p\n", is_sorted_incr(l->a, size), l->b);
	if (l->b == NULL && is_sorted_incr(l->a, size) > 0)
		return (NULL);
	if ((checker(mid, lst_len(l->a), l, grp + 1, ct, newct)))
		return (NULL);
	return (l);
}*/

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lsts	*l;
	//t_lst	*tmp;
	long	mid;
	int		ct;

	ct = 1;
	if (av < 2)
		return (0);
	if ((string_check(av - 1, &ac[1], 0)) == -1)
		return (-1);
	if (!(lst = init_pars(&ac[1], av - 1)))
		return (-1);
	if ((ct = lst_len(lst)) == -1)
		return (-1);
	if ((mid = find_mid(lst, ct)) < -2147483648)
	 	return (-1);
	if (!(l = (t_lsts*)malloc(sizeof(t_lsts))))
		return (0);
	l->a = lst;
	l->b = NULL;
	ft_lst_print_cir(&l->a, -1, -5);
	ft_printf("%d\n", is_sorted_incr(l->a, lst_len(l->a)));
	ft_printf("%d\n", is_sorted_decr(l->a, lst_len(l->a)));
	ft_printf("POS : %d\n", find_pos(l->a, l->a->data, 1, 1));
	l->mid = ct - 1;
	while ((checker(mid, ct, l, 1, 0, 0)))
		//return (-1);
	//ft_lst_print_cir(&l->b, 1, -5);
	ft_lst_print_cir(&l->a, -1, -5);
	return (0);
}
