/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:36:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 11:06:38 by mmanley          ###   ########.fr       */
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
	int				grp;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;
typedef struct		s_lsts
{
	t_lst			*a;
	t_lst			*b;
	int				mid;
}					t_lsts;
int			check_grps(t_lst *l);

int					calc_diff(long a, long b);
int					check_where(t_lst *lst);
int					data_check(t_lst *lst, int curr);
int					find_mid(t_lst *lst, int ct);
int					find_max(t_lst *lst);
int					find_min(t_lst *lst);
int					find_pos(t_lst *lst, int curr, int dir1, int dir2);
void				ft_lst_print_cir(t_lst **alst, int nb_lst, int add);
int					grp_len(t_lst *lst, int grp);
t_lst				*init_pars(char **ac, int av);
int					is_sorted_incr(t_lst *lst, int size);
int					is_sorted_decr(t_lst *lst, int size);
t_lst				*lst_init(long nbr);
void				lst_circular(t_lst **lst, t_lst *new);
int					lst_len(t_lst *lst);
t_lsts				*push_a(t_lsts *l);
t_lsts				*push_b(t_lsts *l);
t_lsts				*push_to_mid(t_lsts *l, int mid, int *ct, int *grp);
void				quicksort(t_lst **lst, int ct);
t_lsts				*quicksort_a(t_lsts *l, int size);
t_lsts				*quick_sort_a(t_lsts *l, int ct);
t_lsts				*quick_sort_b(t_lsts *l);
t_lsts				*reverse(t_lsts *l);
t_lsts				*reverse_a(t_lsts *l);
t_lsts				*reverse_b(t_lsts *l);
t_lsts				*rereverse(t_lsts *l);
t_lsts				*rereverse_a(t_lsts *l);
t_lsts				*rereverse_b(t_lsts *l);
t_lsts				*swap(t_lsts *l);
t_lsts				*swap_a(t_lsts *l);
t_lsts				*swap_b(t_lsts *l);
int					srch(t_lst *lst, int x, int ch);
static	t_lsts		*(*actions[11])(t_lsts *l) =\
{
	swap_a, reverse_a, rereverse_a, push_b, swap_b, reverse_b, rereverse_b,\
	push_a, swap, reverse, rereverse
};
#endif
