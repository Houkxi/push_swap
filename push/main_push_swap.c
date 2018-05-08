/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/08 12:07:19 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_all	*ft_main(t_all *data, int ac, char **av)
{
	if (ft_are_int(ac, av) != 0)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	if (!ft_fill(ac, av, &data))
		return (NULL);
	if (ft_are_sorted_a_exval(data->lst_a) == 0)
		return (NULL);
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a), 0) != 0)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	change_lst(data->lst_a);
	if (ft_are_sorted_a_but(data->lst_a) == 0)
	{
		SA;
		write(1, "sa\n", 3);
		return (NULL);
	}
	return (data);
}

static int		ft_check_av(int ac, char **av)
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

static void		ft_lstclean(t_lst **alst)
{
	t_lst *temp;

	if (alst == NULL)
		return ;
	temp = *alst;
	while (temp->next != *alst)
	{
		free(temp);
		temp = temp->next;
	}
	free(temp);
	*alst = NULL;
}

int				main(int ac, char **av)
{
	t_all	*data;
	int		opt;

	opt = 0;
	if (ac == 1 || (ft_check_av(ac, av) == 0))
		return (0);
	if (!(av = option_check(av, ac, &opt)))
		return (0);
	if ((data = ft_main(NULL, ac, av)) == NULL)
		return (0);
	if (opt & B)
		opts_cmds(data, opt);
	(ft_lstlen(data->lst_a) < 5) ? ft_bubble_algo(data) : ft_quicksort(data);
	if (opt & V || opt & P || opt & B || opt & C)
		opts_cmds(data, opt);
	ft_lstclean(&data->lst_a);
	free(data);
	return (0);
}
