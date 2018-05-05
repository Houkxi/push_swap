/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/03 11:49:53 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_main(t_all *data, int ac, char **av)
{
	if (ft_are_int(ac, av) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ft_fill(ac, av, &data);
	if (ft_are_sorted_a_exval(data->lst_a) == 0)
		return (0);
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a), 0) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_all	*data;
	int		opt;

	opt = 0;
	if (!(av = option_check(av, ac, &opt)))
	{
		ft_printf("Usage: -[Options] [Lists of numbers]\n");
		return (0);
	}
	if (ft_main(data, ac, av) != 1)
		return (0);
	change_lst(data->lst_a);
	if (ft_are_sorted_a_but(data->lst_a) == 0)
	{
		SA;
		write(1, "sa\n", 3);
		return (0);
	}
	if (ft_lstlen(data->lst_a) < 5)
		ft_bubble_algo(data);
	else
		ft_quicksort(data);
	if (opt & V || opt & P || opt & B || opt & C)
		opts_cmds(data, opt);
	return (0);
}
