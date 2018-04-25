/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 10:39:57 by mmanley          ###   ########.fr       */
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

int			push_swap(int mid, int size, t_lsts *l, int grp)
{
	t_lst		*tmp;
	int			ct;
	int			ct2;
	int			ct3;
	int			orgsz;
	int tp = 0;

	tmp = l->a;
	ct = 1;
	ct2 = 0;
	ct3 = 4;
	orgsz = size;
	l->mid = size;
	size -= 1;
	while (orgsz != size)
	{
		if (is_sorted_incr(l->a, size) > 0)
		{
			//ft_lst_print_cir(&l->a, -1, 5);
			if ((ct2 = grp_len(l->b, grp)) == 0)
				grp--;
			ct3 = 0;
			while (ct2-- >= ct3)
			{
				PA;
				ft_printf("pa\n");
				l = quicksort_a(l, size);
				//ft_lst_print_cir(&l->a, -1, 5);
				ct3++;
			}
			//ct += ct3;
			size += ct3;
		}
		if (size > 3)
		{
			ft_printf("MID : %d, ct3 : %d\n", mid, ct3);
			mid = find_mid(l->a, size);
			ft_printf("MID : %d, ct3 : %d\n", mid, ct3);
			if (ct3 > 3)
				push_to_mid(l, mid, &ct, &grp);
			//ft_printf("1sz %d != ct %d\n", size, ct);
			size += ct;
			ct = 0;
			ft_printf("2sz %d != ct %d\n", size, ct);
			ft_lst_print_cir(&l->a, -1, 5);
			tp++;
			/*if (tp == 9)
				while (1);*/
		}
		if (size == 3/* || (ct3 <= 3 && ct3 != 0)*/)
			l = quicksort_a(l, size);
		//ft_printf("ORGSZ = %-7d Size = %-7d Ct = %-7d\n", orgsz, size, ct);
	}
	/*while (is_sorted_incr(l->a, size) == 0)
		l = quicksort_a(l, size);*/
	check_grps(l->a);
	ft_printf("ORGSZ = %-7d Size = %-7d Ct = %-7d\n", orgsz, size, ct);
	ft_printf("Sorted = %d, size %d\n", is_sorted_incr(l->a, size), size);
	ft_printf("TESTing end\n");
	return (0);
}

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lsts	*l;
	t_lst	*tmp;
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
	tmp = l->a;
	while (tmp->next != l->a)
	{
		tmp->grp = -1;
		tmp = tmp->next;
	}
	check_grps(l->a);
	push_swap(mid, ct, l, 1);
	//while ((push_swap(mid, ct, l, 1, 0, 0)))
		//return (-1);
	//ft_lst_print_cir(&l->b, 1, -5);
	ft_lst_print_cir(&l->a, -1, -5);
	return (0);
}
