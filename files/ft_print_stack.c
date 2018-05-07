/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:13:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/07 20:20:13 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_stack(t_lst *lst, char c)
{
	t_lst	*tmp;

	if (!(lst))
		return ;
	tmp = lst->prev;
	(c == 'A') ? write(1, "\x1B[35m", 5) : write(1, "\x1B[32m", 5);
	ft_printf("\n|---Stack_%c---|\n", c);
	while (lst != tmp)
	{
		ft_printf("|%13d|\n", (lst)->exval);
		(lst) = (lst)->next;
	}
	if (tmp)
		ft_printf("|%13d|\n|-------------|\n", (lst)->exval);
}

void		ft_print_2stack(t_lst *lst_a, t_lst *lst_b)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;
	int		len_a;
	int		len_b;

	i = 0;
	if (!(lst_a) && !(lst_b))
		return ;
	(!lst_a && lst_b) ? ft_print_stack(lst_b, 'B') : i++;
	(lst_a && !lst_b) ? ft_print_stack(lst_a, 'A') : i++;
	if (i != 2)
		return ;
	tmp = (lst_a->prev) ? lst_a->prev : lst_a;
	tmp2 = (lst_b->prev) ? lst_b->prev : lst_b;
	len_a = ft_lstlen(lst_a);
	len_b = ft_lstlen(lst_b);
	if (len_a > len_b)
	{
		len_b = len_a - len_b + 1;
		len_a = 0;
	}
	else
	{
		len_a = len_b - len_a + 1;
		len_b = 0;
	}
	write(1, "\x1B[36m", 5);
	ft_printf("\n|---Stack_A---||---Stack_B---|\n");
	while (lst_a != tmp || lst_b != tmp2)
	{
		if (lst_a != tmp && --len_a <= 0)
			ft_printf("|%13d|", (lst_a)->exval);
		else
			ft_printf("|%14|");
		if (lst_b != tmp2 && --len_b <= 0)
			ft_printf("|%13d|\n", (lst_b)->exval);
		else
			ft_printf("|%14|\n");
		if (lst_a != tmp && len_a <= 0)
			(lst_a) = (lst_a->next != tmp) ? (lst_a)->next : tmp;
		if (lst_b != tmp2 && len_b <= 0)
			lst_b = (lst_b->next != tmp2) ? (lst_b)->next : tmp2;
	}
	if (lst_a)
		ft_printf("|%13d|", (lst_a)->exval);
	if (lst_b)
		ft_printf("|%13d|\n", (lst_b)->exval);
	ft_printf("|-------------||-------------|\n");
}

int			loop_spot(t_lst *a, int sv)
{
	t_lst	*tmp;
	int		x;

	x = 0;
	tmp = a;
	while (tmp->next != a)
	{
		if (sv > tmp->exval)
			x++;
		tmp = tmp->next;
	}
	if (sv > tmp->exval)
		x++;
	return (x);
}

t_lst		*change_lst(t_lst *a)
{
	t_lst	*tmp2;
	int		sv;
	int		x;

	if (!a)
		return (NULL);
	tmp2 = a;
	x = 0;
	while (tmp2->next != a)
	{
		sv = tmp2->exval;
		x = loop_spot(a, sv);
		tmp2->val = x;
		tmp2 = tmp2->next;
	}
	sv = tmp2->exval;
	x = loop_spot(a, sv);
	tmp2->val = x;
	return (tmp2);
}

int			ft_are_sorted_a_but(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst->prev;
	lst = lst->next->next;
	while (lst != tmp)
	{
		if (lst->val == (lst->next->val - 1))
			lst = lst->next;
		else
			return (1);
	}
	if (tmp->next->val == 1 && tmp->next->next->val == 0)
		return (0);
	return (1);
}
