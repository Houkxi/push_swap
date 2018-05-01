/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:32:46 by exam              #+#    #+#             */
/*   Updated: 2018/05/01 17:50:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		power(int power)
{
	int i;

	i = 1;
	if (power == 0)
		return (1);
	while (power--)
		i *= 2;
	return (i);
}

static int		ft_occ(char *s, char c)
{
	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	if (s[x] == c)
		return (x);
	return (-1);
}

void	ft_print_bits(unsigned int octet, int size)
{
	int oct;

	oct = octet;
	if (size)
	{
		ft_print_bits(octet >> 1, size - 1);
		ft_putchar('0' + (oct & 1));
		if (size % 8 == 0)
			ft_putchar(' ');
	}
}

char		*options(char *s, int *oct)
{
	int x;
	int ret;

	x = 1;
	ret = 0;
	if (s[0] != '-' || (s[x] == '-' && ft_isdigit(s[x + 1])))
		return (s);
	s[0] = ' ';
	while (s[x])
	{
		ret = ft_occ("abcdefghijklmnopqrstuvwxyz", s[x]);
		if (ret == -1)
			return (NULL);
		s[x] = ' ';
		ret = power(ret);
		*oct |= ret;
		x++;
	}
	return (s);
}

char		**option_check(char **av, int ac, int *opt)
{
	int		sv;
	int		i;
	int		dty;

	i = 1;
	sv = 0;
	dty = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && !(av[i] = options(av[i], &sv)))
		{
			ft_printf("Invalid Option\n");
			return (NULL);
		}
		else if (sv & 128)
		{
			ft_printf("options: abcdefghijklmnopqrstuvwxyz\n");
			return (NULL);
		}
		i++;
	}
	*opt = sv;
	return (av);
}
