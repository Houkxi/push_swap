/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/01 18:35:59 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_all	*data;
	int		opt;

	if (!(av = option_check(av, ac, &opt)))
	{
		ft_printf("option Error\n");
		return (0);
	}
	if (opt & O)
	{
		ft_print_bits(opt, 32);
		ft_printf("\n");
	}
	if (ft_are_int(ac, av) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ft_fill(ac, av, &data);
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a)) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (opt & B)
		ft_print_stack(data->lst_a);
//	if (ft_checker(ac, av, data) != 1)
//		return (-1);
//	ft_try_a(data, ac / 2);
//	ft_print_stack(data->lst_a);
	ft_quicksort(data);
	//ft_printf("-----------\n");
	if (opt & V || opt & P || opt & B || opt & C)
		opts_cmds(data, opt);
	else
		ft_print_moves(data->lst_move);
//	ft_print_stack(data->lst_a);
//	ft_print_stack(data->lst_b);
	return (0);
}
