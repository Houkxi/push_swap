/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annoying_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 16:55:22 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/11 16:56:46 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			rec_nbr_count(long long int nb, int i, int base)
{
	if (nb < 0)
	{
		if (base == 10)
			i++;
		nb *= -1;
	}
	if (nb >= base)
		return (rec_nbr_count(nb / base, i + 1, base));
	return (i);
}

int					ft_check_validity(char *s)
{
	int				x;
	int				ct;
	long long int	nb;

	x = 0;
	ct = ft_strlen(s);
	if (s[x])
	{
		if (s[0] == '-' || s[0] == '+')
			x++;
		if (x == 0 || x == 1)
			while (s[x] && s[x] == '0')
				x++;
		nb = ft_atoi(&s[x]);
		if (nb < 0)
			nb *= -1;
		if (ct - x != rec_nbr_count(nb, 1, 10))
			return (-1);
	}
	return (0);
}
