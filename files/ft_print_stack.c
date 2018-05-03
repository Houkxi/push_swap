/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:13:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/20 16:24:02 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_lst *lst)
{
	t_lst *tmp;

	if (!(lst))
		return ;
	tmp = lst->prev;
	while (lst != tmp)
	{
		ft_printf("%d--%d\n", (lst)->exval, lst->val);
		(lst) = (lst)->next;
	}
	if (tmp)
		ft_printf("%d--%d\n------\n", (lst)->exval, lst->val);
}

/*void	ft_print_moves(t_moves *lst)
{
	t_moves *tmp;

	tmp = lst;
	if (!(tmp))
		return ;
	while (tmp->next)
	{
		ft_putstr(tmp->move);
		tmp = tmp->next;
	}
	ft_putstr(tmp->move);
}*/