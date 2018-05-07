/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:39:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/07 20:31:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_errors(t_lst *a, int len, int i)
{
	int		*arr;
	int		k;
	t_lst	*temp;

	temp = a;
	if (!(arr = malloc(sizeof(int) * len)))
		return (-1);
	arr[i] = a->exval;
	a = a->next;
	while (a != temp)
	{
		k = 0;
		i++;
		arr[i] = a->exval;
		while (k < i)
		{
			arr[i] != arr[k] ? k++ : 0;
			if (arr[i] == arr[k] && i != k)
				return (-1);
		}
		a = a->next;
	}
	free(arr);
	return (0);
}

int			ft_are_int(int ac, char **av)
{
	int i;
	int k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		if (av[i][k + 1] && av[i][k] == '-' && ft_isdigit(av[i][k + 1]))
			k++;
		while (ft_isdigit(av[i][k]) || av[i][k] == ' ' || (av[i][k] == '-' &&
				av[i][k - 1] == ' ' && ft_isdigit(av[i][k + 1])))
			k++;
		if (av[i][k])
			return (1);
		if (ft_atoll(av[i]) > INT_MAX)
			return (1);
		if (ft_atoll(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int			ft_take_com(char *com, t_all *data, int opt)
{
	char	**tab;
	int		y;

	tab = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (get_next_line(0, &com) > 0)
	{
		y = 0;
		while (tab[y])
		{
			if (ft_strequ(tab[y], com) == 1)
				break ;
			y++;
		}
		if (y > 10)
			return(-1);
		free(com);
		com = NULL;
		data->tab_f[y].f(&data->lst_a, &data->lst_b);
		if (opt & C)
		{
			sleep(1);
			ft_printf("0\033[H\033[2J");
			ft_print_2stack(data->lst_a, data->lst_b);
		}
	}
	return (0);
}

int			ft_checker(int ac, char **av, t_all *data, int opt)
{
	int		i;
	char	*com;

	i = 0;
	if (!(data->lst_a))
		return (0);
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a), 0) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	write(1, "\x1B[0m", 5);
	if (ft_take_com(com, data, opt) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (data->lst_a && ft_are_sorted_a_exval(data->lst_a) == 0
	 	&& (data->lst_b == NULL))
	{
		write(1, "\x1B[32m", 5);
		ft_printf("OK\n");
	}
	else
	{
		write(1, "\x1B[31m", 5);
		ft_printf("KO\n");
	}
	return (1);
}
