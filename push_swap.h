/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:36:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/17 18:00:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define SA l = (*actions[0])(l)
# define RA l = (*actions[1])(l)
# define RRA l = (*actions[2])(l)
# define PB	l = (*actions[3])(l)
# define SB l = (*actions[4])(l)
# define RB l = (*actions[5])(l)
# define RRB l = (*actions[6])(l)
# define PA	l = (*actions[7])(l)
# define AA l->a->data
# define AB l->a->next->data
# define AZ l->a->prev->data
# define BA l->b->data
# define BB l->b->next->data
# define BZ l->b->prev->data

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
int					find_mid(t_lst *lst, int ct);
t_lsts				*swap_a(t_lsts *l);
t_lsts				*reverse_a(t_lsts *l);
t_lsts				*rereverse_a(t_lsts *l);
t_lsts				*push_a(t_lsts *l);
t_lsts				*swap_b(t_lsts *l);
t_lsts				*reverse_b(t_lsts *l);
t_lsts				*rereverse_b(t_lsts *l);
t_lsts				*push_b(t_lsts *l);
int					lst_ct_size(t_lst *lst);
t_lsts				*push_to_mid(t_lsts *l, int mid);
t_lsts				*quick_sort_b(t_lsts *l);
t_lsts				*quick_sort_a(t_lsts *l);
int					ft_is_sorted(t_lst *lst, int size);
int					ft_is_sorted_other_side(t_lst *lst, int size);
static	t_lsts		*(*actions[8])(t_lsts *l) =\
{
	swap_a, reverse_a, rereverse_a, push_b, swap_b, reverse_b, rereverse_b,\
	push_a
};

#endif
