/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/08 14:17:03 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_av(int ac, char **av)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (i < ac - 1)
	{
		i++;
		if (av[i][0] == '\0')
			k++;
		if (k == ac)
			return (0);
	}
	return (1);
}

static void	ft_print_check(void)
{
	char	*com;

	com = NULL;
	get_next_line(0, &com);
	if (ft_strequ(com, "") == 1)
	{
		write(1, "\x1B[32m", 5);
		ft_printf("OK\n");
	}
	else
		ft_printf("Error\n");
}

int			main(int ac, char **av)
{
	t_all	*data;
	int		opt;

	opt = 0;
	write(1, "\x1B[33m", 5);
	if (ac == 1 || (ft_check_av(ac, av) == 0))
		return (0);
	if (!(av = option_check(av, ac, &opt)))
		return (0);
	if (ft_are_int(ac, av) != 0)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ft_fill(ac, av, &data);
	if (!(data->lst_a))
		return (0);
	if (ft_are_sorted_a_exval(data->lst_a) == 0)
	{
		ft_print_check();
		return (0);
	}
	if (ft_checker(ac, av, data, opt) != 1)
		return (-1);
	return (0);
}
