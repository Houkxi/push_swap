/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:55:21 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 17:57:46 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_big_deltab(char ***btab, int av)
{
	int			z;

	z = 0;
	if (btab)
	{
		while (z < av)
		{
			ft_deltab(btab[z]);
			z++;
		}
		free(btab);
		btab = NULL;
	}
}

void			ft_lst_print_cir(t_lst **alst, int nb_lst, int add)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	if (alst)
	{
		tmp = *alst;
		ft_printf("\n*************\n");
		while (tmp->next != *alst)
		{
			if (nb_lst <= 0)
			{
				ft_printf("A LIST : %- 12d", tmp->data);
				if (add < 0)
					ft_printf("	---adresse--> %p , --Next--> %p --spot--> %d", tmp, tmp->next, tmp->spot);
				ft_printf("\n");
			}
			else
			{
				ft_printf("B LIST : %- 10d", tmp->data);
				if (add < 0)
					ft_printf("	---adresse--> %p , --Next--> %p --spot--> %d", tmp, tmp->next, tmp->spot);
				ft_printf("\n");
			}
			tmp = tmp->next;
		}
		ft_printf("E DATA : %- 12d", tmp->data);
		if (add < 0)
		{
			ft_printf("	---adresse---> %p, --Next--> %p\n", tmp, tmp->next);
			ft_printf("%25y--spot--> %d", tmp->spot);
		}
		ft_printf("\n*************\n");
	}
}

static	t_lst	*pars_nbrs(char **nbrs, int av, t_lst *lst)
{
	int			y;
	long		nb;
	t_lst		*tmp;

	y = 0;
	av = 0;
	while (nbrs[y])
	{
		nb = ft_atoi(nbrs[y]);
		y++;
		if (!(tmp = lst_init(nb)))
			return (NULL);
		if (data_check(lst, tmp->data) == -1)
		{
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		lst_circular(&lst, tmp);
	}
	return (lst);
}

t_lst			*init_pars(char **ac, int av)
{
	t_lst		*lst;
	t_lst		*tmp;
	int			z;
	char		***nbrs;

	z = 0;
	lst = NULL;
	if (!(nbrs = (char***)malloc(sizeof(char**) * av)))
		return (NULL);
	nbrs[av] = NULL;
	while (z < av)
	{
		if (!(nbrs[z] = ft_strsplit(ac[z], ' ')))
			return (NULL);
		z++;
	}
	z = 0;
	while (z < av)
	{
		if (!(tmp = pars_nbrs(nbrs[z], av, lst)))
		{
			ft_big_deltab(nbrs, av);
			return (NULL);
		}
		lst = tmp;
		z++;
	}
	ft_big_deltab(nbrs, av);
	return (lst);
}

t_lsts			*spot_srch(t_lsts *l)
{
	t_lst		*tmp;
	t_lst		*tmp2;
	int			sv;
	int			x;

	tmp = l->a;
	tmp2 = l->a;
	x = 0;
	while (tmp2->next != l->a)
	{
		sv = tmp2->data;
		while (tmp->next != l->a)
		{
			if (sv > tmp->data)
				x++;
			tmp = tmp->next;
		}
		if (sv > tmp->data)
			x++;
		tmp2->spot = x;
		x = 0;
		tmp2 = tmp2->next;
		tmp = l->a;
	}
	sv = tmp2->data;
	while (tmp->next != l->a)
	{
		if (sv > tmp->data)
			x++;
		tmp = tmp->next;
	}
	if (sv > tmp->data)
		x++;
	tmp2->spot = x;
	return (l);
}
