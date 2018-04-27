/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/27 19:54:53 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			string_check(int av, char **ac, int ch)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < av)
	{
		while (ac[y][x])
		{
			if ((ch = ft_occ_pos("-0123456789 ", ac[y][x])) == -1 ||
			(ac[y][x] == '-' && ((ac[y][x - 1] != ' ' && x != 0) ||
			ft_isdigit(ac[y][x + 1]) == 0)))
			{
				ft_printf("_%c_\nError, %3d\n", ac[y][x], ch);
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void		ft_grpadd(t_grp **alst, t_grp *new)
{
	new->next = *alst;
	*alst = new;
}

t_grp		*ft_first_push(t_lsts **data, int elem_lst_a, t_grp *lst)
{
	int		middle;
	int		elements;
	int		max;
	t_grp	*lst_new;

	while (elem_lst_a > 3)
	{
		elements = 0;
		middle = ft_find_middle((*data)->a, 0, elem_lst_a);
		if (elem_lst_a > 3)
			max = (elem_lst_a / 2);
		else
			max = elem_lst_a;
		elements = ft_move_on_b(*data, middle, max);
		if (!(lst_new = (t_grp*)malloc(sizeof(t_grp))))
			return (NULL);
		ft_grpadd(&lst, lst_new);
		lst->group = elements;
		elem_lst_a = elem_lst_a - elements;
	}
	return (lst);
}

int		ft_quicksort(t_lsts *data)
{
	t_grp	*lst;
	int		elem_lst_a;
	int		middle;

	change_lst(data->a);
	if (ft_are_sorted_a(data->a) == 0)
		return (0);
	elem_lst_a = ft_lstlen((data)->a);
	lst = ft_first_push(&data, elem_lst_a, NULL);
	ft_solve_a(data);
	elem_lst_a = 0;
	while (data->b)
	{
			middle = (lst->group > 2) ? \
				ft_find_middle((data)->b, 0, lst->group) : INT_MIN;
			elem_lst_a = ft_move_on_a(data, middle, &lst->group);
			(lst->group == 0 && lst->next) ? lst = lst->next : 0;
			(ft_are_sorted_a((data)->a) == 0) ? elem_lst_a = 0 : 0;
			lst = ft_first_push(&data, elem_lst_a, lst);
			elem_lst_a = ft_solve_a(data);
	}
	return (1);
}

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lsts	*l;
	int		ct;

	ct = 1;
	if (av < 2)
		return (0);
	if ((string_check(av - 1, &ac[1], 0)) == -1)
		return (-1);
	if (!(lst = init_pars(&ac[1], av - 1)))
		return (-1);
	if (!(l = (t_lsts*)malloc(sizeof(t_lsts))))
		return (0);
	l->a = lst;
	l->b = NULL;
	//ft_printf("PAS COMPRIS\n");
	ft_quicksort(l);
	//ft_lst_print_cir(&l->a, -1, 5);
	return (0);
}
