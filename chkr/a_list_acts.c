/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_list_acts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:27:08 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 18:11:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap_a(t_lsts *l)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = l->a;
	tmp2 = l->a->next;
	l->a = l->a->next;
	tmp1->next = l->a->next;
	l->a->next = tmp1;
	l->a->prev = tmp1->prev;
	tmp1->prev = l->a;
	l->a->prev->next = l->a;
	if (lst_len(l->a) <= 3)
		l->a->prev->prev = l->a->next;
	return (l);
}

t_lsts		*reverse_a(t_lsts *l)
{
	l->a = l->a->next;
	return (l);
}

t_lsts		*rereverse_a(t_lsts *l)
{
	l->a = l->a->prev;
	return (l);
}

t_lsts		*push_b(t_lsts *l)
{
	t_lst	*tmpa;
	t_lst	*tmpb;

	tmpa = l->a;
	l->a = l->a->next;
	l->a->prev = tmpa->prev;
	l->a->prev->next = l->a;
	if (!l->b)
	{
		l->b = tmpa;
		l->b->prev = l->b;
		l->b->next = l->b;
	}
	else
	{
		tmpb = l->b;
		l->b = tmpa;
		l->b->next = tmpb;
		l->b->prev = tmpb->prev;
		l->b->prev->next = tmpa;
		l->b->next->prev = tmpa;
	}
	return (l);
}
