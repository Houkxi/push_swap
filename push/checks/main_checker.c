/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/09 19:56:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_av(int ac, char **av)
{
	int		i;
	int		k;
	size_t	j;

	i = 0;
	k = 1;
	while (i < ac - 1)
	{
		i++;
		if (av[i][0] == '\0' || av[i][0] == ' ')
		{
			j = 0;
			while (av[i][j] == ' ')
				j++;
			if (av[i][0] == '\0' || j == ft_strlen(av[i]))
				k++;
		}
		if (k == ac)
			return (0);
	}
	return (1);
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
	if (ft_fill(ac, av, &data) == -1)
		return (-1);
	if (!(data->lst_a))
		return (0);
	if (ft_checker(data, opt) != 1)
		return (ft_random_2(data, -1));
	return (ft_random_2(data, 0));
}
