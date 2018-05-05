/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:13:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/03 12:20:45 by mmanley          ###   ########.fr       */
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
