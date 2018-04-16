/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:36:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/16 13:17:50 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define PB	l = (*actions[3])(la, lb, l)
# define PA	l = (*actions[3])(lb, la, l)
# define RA l = (*actions[1])(la, lb, l)
# define SA l = (*actions[0])(la, lb, l)

typedef struct		s_lst
{
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;
typedef struct		s_lsts
{
	t_lst			*a;
	t_lst			*b;
	int				mid;
}					t_lsts;

t_lst				*lst_init(long nbr);
void				lst_circular(t_lst **lst, t_lst *new);
t_lst				*init_pars(char **ac, int av);
int					data_check(t_lst *lst, int curr);
void				ft_lst_print_cir(t_lst **alst, int nb_lst, int add);
void				quicksort(t_lst **lst, int ct);
t_lst				*find_mid(t_lst *lst, int ct);
t_lsts				*swap(t_lst *a, t_lst *b, t_lsts *l);
t_lsts				*reverse(t_lst *a, t_lst *b, t_lsts *l);
t_lsts				*rereverse(t_lst *a, t_lst *b, t_lsts *l);
t_lsts				*push(t_lst *a, t_lst *b, t_lsts *l);
static	t_lsts		*(*actions[4])(t_lst *a, t_lst *b, t_lsts *l) =\
{
	swap, reverse, rereverse, push
};

#endif
