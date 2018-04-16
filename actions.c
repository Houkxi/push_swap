/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:27:08 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/16 13:17:31 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap(t_lst *a, t_lst *b, t_lsts *l)
{
	t_lst	*tmp;

	tmp = (t_lst*)malloc(sizeof(t_lst));
	tmp->data = a->data;
	a->data = a->next->data;
	a->next->data = tmp->data;
	l->a = a;
	l->b = b;
	free(tmp);
	tmp = NULL;
	return (l);
}

t_lsts		*reverse(t_lst *a, t_lst *b, t_lsts *l)
{
	l->a = a->next;
	l->b = b;
	return (l);
}

t_lsts		*rereverse(t_lst *a, t_lst *b, t_lsts *l)
{
	l->a = a->prev;
	l->b = b;
	return (l);
}

t_lsts		*push(t_lst *a, t_lst *b, t_lsts *l)
{
	t_lst	*tmpa;
	t_lst	*tmpb;

	if (!(tmpa = (t_lst*)malloc(sizeof(t_lst))) ||
	!(tmpb = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	tmpa->next = a->next;
	tmpa->prev = a->prev;
	lst_circular(&b, a);
	tmpb->next = b->next;
	tmpb->prev = b->prev;
	tmpa->next->prev = tmpa->prev;
	tmpa->prev->next = tmpa->next;
	l->a = tmpa->next;
	l->b = a;
	free(tmpa);
	free(tmpb);
	tmpa = NULL;
	tmpb = NULL;
	return (l);
}
