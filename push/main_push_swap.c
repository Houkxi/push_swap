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
	if (ft_are_int(ac, av) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ft_fill(ac, av, &data);
	if (ft_are_sorted_a_exval(data->lst_a) == 0)
		return (0);
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a)) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
//	if (ft_checker(ac, av, data) != 1)
//		return (-1);
//	ft_try_a(data, ac / 2);
	// ft_print_stack(data->lst_a);
	ft_quicksort(data);
	if (opt & V || opt & P || opt & B || opt & C)
		opts_cmds(data, opt);
	//ft_print_moves(data->lst_move);
	//data->lst_move = ft_cleaning_lst(data, data->lst_move);
	// ft_print_moves(data->lst_move);
	//ft_free_moves(data->lst_move);
//	ft_print_stack(data->lst_a);
	//ft_printf("-----------\n");s
//	ft_print_stack(data->lst_b);
	return (0);
}
