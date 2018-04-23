/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_list_acts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:27:08 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/19 18:38:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap_a(t_lsts *l)
{
	t_lst	*tmp;

	tmp = (t_lst*)malloc(sizeof(t_lst));
	tmp->data = l->a->data;
	l->a->data = l->a->next->data;
	l->a->next->data = tmp->data;
	free(tmp);
	tmp = NULL;
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
		//l = quick_sort_b(l);
	}
	return (l);
}
