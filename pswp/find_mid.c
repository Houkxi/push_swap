/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:19:19 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/27 19:42:24 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*ft_get_arr(t_lst *a, int len)
{
	int		*arr;
	int		i;
	t_lst	*temp;

	i = 0;
	temp = a;
	if (!(arr = malloc(sizeof(int) * len)))
		return (NULL);
	arr[i] = a->val;
	a = a->next;
	while (len--)
	{
		i++;
		arr[i] = a->val;
		a = a->next;
	}
	return (arr);
}

int			ft_find_middle(t_lst *lst, int k, int len)
{
	int		val;
	int		more;
	int		less;
	int		i;
	int		*arr;

	if (len == 0)
		len = ft_lstlen(lst);
	arr = ft_get_arr(lst, len);
	k = len;
	while (k--)
	{
		i = 0;
		more = 0;
		less = 0;
		val = arr[k];
		while (i < len)
		{
			if (val < arr[i])
				more++;
			else
				less++;
			i++;
		}
		if (more - less == 0 || (len % 2 == 1 && more - less == 1))
			return (val);
	}
	return (val);
}
