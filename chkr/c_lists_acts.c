/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lists_acts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:45:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 10:48:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap(t_lsts *l)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = (t_lst*)malloc(sizeof(t_lst));
	tmp2 = (t_lst*)malloc(sizeof(t_lst));
	tmp1->data = l->a->data;
	l->a->data = l->a->next->data;
	l->a->next->data = tmp1->data;
	tmp2->data = l->b->data;
	l->b->data = l->b->next->data;
	l->b->next->data = tmp2->data;
	free(tmp1);
	free(tmp2);
	tmp1 = NULL;
	tmp2 = NULL;
	return (l);
}

t_lsts		*reverse(t_lsts *l)
{
	l->a = l->a->next;
	l->b = l->b->next;
	return (l);
}

t_lsts		*rereverse(t_lsts *l)
{
	l->a = l->a->prev;
	l->b = l->b->prev;
	return (l);
}
