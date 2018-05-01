/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:13:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/01 18:11:22 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_lst *lst)
{
	t_lst *tmp;

	if (!(lst))
		return ;
	tmp = lst->prev;
	ft_printf("\n--STACK--\n");
	while (lst != tmp)
	{
		ft_printf("% -5d\n", (lst)->exval);
		(lst) = (lst)->next;
	}
	if (tmp)
		ft_printf("% -5d\n---------\n", (lst)->exval);
}

void	ft_print_moves(t_moves *lst)
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
}
