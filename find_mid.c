/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:19:19 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/16 09:33:12 by mmanley          ###   ########.fr       */
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
		return (0);
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
		return (0);
	else
		return (-1);
}

t_lst		*find_mid(t_lst *lst, int ct)
{
	int		mid;
	t_lst	*tmp;

	mid = -2;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (ct % 2 == 0)
			mid = mid_4_even(lst, tmp->data, ct);
		if (ct % 2 == 1)
			mid = mid_4_odd(lst, tmp->data, ct);
		if (mid == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
