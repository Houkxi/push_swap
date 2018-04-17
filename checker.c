/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 15:44:18 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_sorted(t_lst *lst, int size)
{
	int		x;
	t_lst	*tmp;

	x = 0;
	if (!lst)
		return (-1);
	tmp = lst;
	while (x < size && tmp->next != lst)
	{
		if (tmp->data < tmp->next->data)
			x++;
		else
		{
			x = 0;
			break ;
		}
		tmp = tmp->next;
	}
	return (x);
}

int			lst_ct_size(t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	i = 1;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != lst)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

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

t_lst		*checker(int mid, int size, t_lsts *l)
{
	l->mid = size;
	ft_printf("%d\n", mid);
	while (size > 3)
	{
		l = push_to_mid(l, mid);
		if (!(ft_is_sorted(l->b, lst_ct_size(l->b))))
			l = quick_sort_b(l);
		while (1);
		size = lst_ct_size(l->a);
		if (size > 3)
		{
			l->mid = size;
			mid = (int)find_mid(l->a, size);
		}
	}
	//ft_lst_print_cir(&l->a, -1, -5);
	//ft_lst_print_cir(&l->b, 1, -5);
	return (l->a);
}

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lsts	*l;
	t_lst	*tmp;
	long		i;
	int		ct;

	ct = 1;
	if (av < 2)
		return (0);
	if ((string_check(av - 1, &ac[1], 0)) == -1)
		return (-1);
	if (!(lst = init_pars(&ac[1], av - 1)))
		return (-1);
	if ((ct = lst_ct_size(lst)) == -1)
		return (-1);
	if ((i = find_mid(lst, ct)) < -2147483648)
	 	return (-1);
	if (!(l = (t_lsts*)malloc(sizeof(t_lsts))))
		return (0);
	l->a = lst;
	l->b = NULL;
	ft_lst_print_cir(&l->a, -1, -5);
	if (!(tmp = checker(i, ct, l)))
		return (-1);
	return (0);
}
