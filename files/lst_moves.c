/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:16:44 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/03 12:14:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_moves	*ft_init_lst(char *s, t_moves *new)
{
	if (!(new = (t_moves*)malloc(sizeof(t_moves))))
		return (NULL);
	new->move = ft_strdup(s);
	new->next = NULL;
	return (new);
}

void			ft_lstadd_end(t_moves **alst, t_moves *new, char *s)
{
	t_moves *tmp;

	new = ft_init_lst(s, new);
	if (*alst)
	{
		tmp = (*alst);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (new)
	{
		*alst = new;
	}
}
