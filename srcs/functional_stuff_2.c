/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional_stuff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:51:23 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 14:00:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			calc_diff(long a, long b)
{
	long	res;

	res = a + (-1 * b);
	if (res < -2147483648 || res > 2147483647)
		return (2147483647);
	if (res < 0)
		return ((int)-res);
	else
		return ((int)res);
}

int			srch(t_lst *lst, int x, int ch)
{
	t_lst	*tmp;

	tmp = lst;
	if (ch >= 0)
	{
		while (x--)
			tmp = tmp->next;
	}
	else
	{
		while (x--)
			tmp = tmp->prev;
	}
	return (tmp->data);
}

int			find_pos(t_lst *lst, int curr, int dir1, int dir2)
{
	int		ct;
	int		res1;
	int		res2;
	t_lst	*tmp1;
	t_lst	*tmp2;

	ct = 1;
	tmp1 = lst->next;
	tmp2 = lst->prev;
	res1 = calc_diff(curr, tmp1->data);
	res2 = calc_diff(curr, tmp2->data);
	while (tmp1 != tmp2 && ct <= lst_len(lst))
	{
		if (res1 > calc_diff(curr, tmp1->data))
		{
			res1 = calc_diff(curr, tmp1->data);
			if (curr > tmp1->data)
				dir1 = ct;
		}
		if (res2 > calc_diff(curr, tmp2->data))
		{
			res2 = calc_diff(curr, tmp2->data);
			if (curr < tmp2->data)
				dir2 = ct;
		}
		//ft_printf("\n%p\n%p\nprev = %d, curr = %d, next = %d\nres2 = %d, 		res1 = %d\ndir1 = %d, dir2 = %d, ct = %d\n", tmp1->next, tmp2->prev, tmp2->data, curr, tmp1->data, res2, res1, dir1, dir2, ct);
		ct++;
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
	}
	if (dir1 == dir2 && srch(lst, dir1, 1) > srch(lst, dir2, -1))
		dir1++;
	if (dir2 < dir1)
		return (-dir2);
	else
		return (dir1);
}

int			grp_len(t_lst *lst, int grp)
{
	t_lst	*tmp;
	int		ct;

	tmp = lst;
	ct = 0;
	while (tmp->next != lst)
	{
		if (tmp->grp == grp)
			ct++;
		tmp = tmp->next;
	}
	return (ct);
}

int			check_where(t_lst *lst)
{
	int		len;
	int		ct;
	t_lst	*tmp;

	len = lst_len(lst);
	ct = 0;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data > tmp->next->data)
		{
			tmp = tmp->next;
			break ;
		}
		ct++;
		tmp = tmp->next;
	}
	if (len - ct < len / 2)
		return (-(len - ct));
	else
		return (ct);
}
