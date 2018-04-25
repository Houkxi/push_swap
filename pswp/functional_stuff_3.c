/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional_stuff_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:54:03 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 14:26:42 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_grps(t_lst *l)
{
	t_lst	*tmp;

	tmp = l;
	while (tmp->next != l)
	{
		ft_printf("GRP : %d\n", tmp->grp);
		tmp = tmp->next;
	}
	ft_printf("GRP : %d\n", tmp->grp);
	return (0);
}

int			*tab_creat(int size)
{
	int		x;
	int		*tab;

	x = 0;
	if (size <= 0)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(int) * size + 1)))
		return (NULL);
	while (x < size)
	{
		tab[x] = x;
		x++;
	}
	tab[x] = x;
	return (tab);
}

int			tab_cmp_sort(int *tab, t_lst *a)
{
	int		x;
	t_lst	*tmp;

	x = 0;
	tmp = a;
	if (!tab || !a)
		return (-1);
	ft_printf("%d\n", tab[x], a->spot);
	while (tmp->next != a)
	{
		ft_printf("%d\n", tab[x]);
		if (tab[x] != tmp->spot)
			return (-1);
		x++;
		tmp = tmp->next;
	}
	return (x);
}
