/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_list_acts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:14:04 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 18:12:02 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap_b(t_lsts *l)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = l->b;
	tmp2 = l->b->next;
	l->b = l->b->next;
	tmp1->next = l->b->next;
	l->b->next = tmp1;
	l->b->prev = tmp1->prev;
	tmp1->prev = l->b;
	l->b->prev->next = l->b;
	if (lst_len(l->b) <= 3)
		l->b->prev->prev = l->b->next;
	return (l);
}

t_lsts		*reverse_b(t_lsts *l)
{
	l->b = l->b->next;
	return (l);
}

t_lsts		*rereverse_b(t_lsts *l)
{
	l->b = l->b->prev;
	return (l);
}

t_lsts		*push_a(t_lsts *l)
{
	t_lst	*tmpa;
	t_lst	*tmpb;

	tmpb = l->b;
	if (lst_len(l->b) == 1)
		l->b = NULL;
	else
	{
		l->b = l->b->next;
		l->b->prev = tmpb->prev;
		l->b->prev->next = l->b;
	}
	tmpa = l->a;
	l->a = tmpb;
	l->a->next = tmpa;
	l->a->prev = tmpa->prev;
	l->a->prev->next = l->a;
	l->a->next->prev = l->a;
	return (l);
}
