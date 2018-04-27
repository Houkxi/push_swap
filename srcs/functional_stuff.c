/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:31:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/27 19:36:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_are_sorted_a(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst->prev;
	while (lst != tmp)
	{
		if (lst->val == (lst->next->val - 1))
			lst = lst->next;
		else
			return (1);
	}
	return (0);
}

int			ft_lstlen(t_lst *lst)
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

int		loop_spot(t_lst *a, int sv)
{
	t_lst	*tmp;
	int	x;

	x = 0;
	tmp = a;
	while (tmp->next != a)
	{
		if (sv > tmp->data)
			x++;
		tmp = tmp->next;
	}
	if (sv > tmp->data)
		x++;
	return (x);
}

t_lst	*change_lst(t_lst *a)
{
	t_lst       *tmp2;
	int         sv;
	int         x;

	tmp2 = a;
	x = 0;
	while (tmp2->next != a)
	{
		sv = tmp2->data;
		x = loop_spot(a, sv);
		tmp2->val = x;
		tmp2 = tmp2->next;
	}
	sv = tmp2->data;
	x = loop_spot(a, sv);
	tmp2->val = x;
	return (tmp2);
}
