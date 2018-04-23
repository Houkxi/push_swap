/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:31:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/23 14:15:49 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted_incr(t_lst *lst, int size)
{
	int		x;
	t_lst	*tmp;

	x = 1;
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

int			is_sorted_decr(t_lst *lst, int size)
{
	int		x;
	t_lst	*tmp;

	x = 1;
	if (!lst)
		return (-1);
	tmp = lst;
	while (x < size && tmp->next != lst)
	{
		if (tmp->data > tmp->next->data)
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

int			lst_len(t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	i = 1;
	if (!lst)
		return (0);
	tmp = lst;
	if (tmp->next == tmp)
		return (1);
	while (tmp->next != lst)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			find_min(t_lst *lst)
{
	t_lst	*tmp;
	int		tp;

	tp = 2147483647;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data <= tp)
			tp = tmp->data;
		tmp = tmp->next;
	}
	if (tmp->data <= tp)
		tp = tmp->data;
	return (tp);
}

int			find_max(t_lst *lst)
{
	t_lst	*tmp;
	int		tp;

	tp = -2147483648;
	tmp = lst;
	while (tmp->next != lst)
	{
		if (tmp->data >= tp)
			tp = tmp->data;
		tmp = tmp->next;
	}
	if (tmp->data <= tp)
		tp = tmp->data;
	return (tp);
}
