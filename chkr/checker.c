/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:20:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 17:56:25 by mmanley          ###   ########.fr       */
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
				ft_printf("Error\n");
				return (-1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int			cmd_tabcmp(char *s, char **tab)
{
	int		y;

	y = 0;
	if (!tab || !s)
		return (-1);
	while (y < 10)
	{
		if (ft_strcmp(tab[y], s) == 0)
			return (y);
		y++;
	}
	if (ft_strcmp(tab[y], s) == 0)
		return (y);
	return (-1);
}

int			checker(t_lsts *l, char *cmd)
{
	char	**tab;
	int		nb;

	tab = ft_strsplit("sa ra rra pb sb rb rrb pa ss rr rrr", ' ');
	while (get_next_line(0, &cmd) > 0)
	{
		nb = cmd_tabcmp(cmd, tab);
		if (nb >= 0 && nb <= 10)
		{
			if (!(nb >= 4 && nb <= 10 && l->b == NULL))
				l = (*actions[nb])(l);
		}
		
		ft_lst_print_cir(&l->a, -1, -5);
		if (l->b != NULL)
			ft_lst_print_cir(&l->b, -1, -5);
	}
	return (0);
}

int			main(int av, char **ac)
{
	t_lst	*lst;
	t_lsts	*l;
	char	*str;
	int		ct;

	ct = 1;
	str = NULL;
	if (av < 2)
		return (0);
	if ((string_check(av - 1, &ac[1], 0)) == -1)
		return (-1);
	if (!(lst = init_pars(&ac[1], av - 1)))
		return (-1);
	if ((ct = lst_len(lst)) == -1)
		return (-1);
	if (!(l = (t_lsts*)malloc(sizeof(t_lsts))))
		return (0);
	l->a = lst;
	l->b = NULL;
	ft_lst_print_cir(&l->a, -1, 5);
	if (is_sorted_incr(l->a, ct) == ct)
	{
		ft_printf("Already sorted\n");
		return (0);
	}
	checker(l, str);
	ft_lst_print_cir(&l->a, -1, 5);
	if (is_sorted_incr(l->a, ct) == ct)
		ft_printf("OK\n");
	return (0);
}
