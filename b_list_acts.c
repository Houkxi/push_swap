/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_list_acts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:14:04 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 12:49:54 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsts		*swap_b(t_lsts *l)
{
	t_lst	*tmp;

	tmp = (t_lst*)malloc(sizeof(t_lst));
	tmp->data = l->b->data;
	l->b->data = l->b->next->data;
	l->b->next->data = tmp->data;
	free(tmp);
	tmp = NULL;
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

t_lsts		*push_b(t_lsts *l)
{
	t_lst	*tmpa;
	t_lst	*tmpb;

	tmpb = l->b;
	l->b = l->a->next;
	l->b->prev = tmpb->prev;
	l->b->prev->next = l->b;
	if (!l->b)
	{
		//ft_printf("*********NEW**********\n");
		l->a = tmpb;
		l->a->prev = l->a;
		l->a->next = l->a;
	}
	else
	{
		//ft_printf("*********OTHER**********\n");
		tmpa = l->a;
		l->a = tmpb;
		l->a->next = tmpa;
		l->b->prev = tmpa->prev;
		l->a->prev->next = tmpb;
		l->a->next->prev = tmpb;

	}
	//ft_lst_print_cir(&l->a, -1, -5);
	//ft_lst_print_cir(&l->b, 1, -5);
	return (l);
}
