/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:19:19 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 14:29:19 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			mid_4_odd(t_lst *lst, int mid, int size)
{
	int		ct1;
	int		ct2;
	t_lst	*tmp;

	ct1 = 0;
	ct2 = 0;
	tmp = lst;
	while (ct1 + ct2 < size - 1)
	{
		if (mid > tmp->data)
			ct1++;
		else if (mid < tmp->data)
			ct2++;
		tmp = tmp->next;
	}
	if (ct1 == ct2)
		return (mid);
	else
		return (-1);
}

int			mid_4_even(t_lst *lst, int mid, int size)
{
	int		ct1;
	int		ct2;
	t_lst	*tmp;

	ct1 = 0;
	ct2 = 0;
	tmp = lst;
	while (ct1 + ct2 < size)
	{
		if (mid >= tmp->data)
			ct1++;
		else if (mid <= tmp->data)
			ct2++;
		tmp = tmp->next;
	}
	if (ct1 == ct2)
		return (mid);
	else
		return (-1);
}

int		find_mid(t_lst *lst, int ct)
{
	int		mid;
	int		size;
	t_lst	*tmp;

	mid = -2;
	tmp = lst;
	size = ct;
	while (size--)
	{
		if (ct % 2 == 0)
			mid = mid_4_even(lst, tmp->data, ct);
		if (ct % 2 == 1)
			mid = mid_4_odd(lst, tmp->data, ct);
		if (mid != -1)
			return (tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
