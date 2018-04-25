/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:36:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/25 18:26:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define SA l = moves(l, 0)
# define RA l = moves(l, 1)
# define RRA l = moves(l, 2)
# define PB	l = moves(l, 3)
# define SB l = moves(l, 4)
# define RB l = moves(l, 5)
# define RRB l = moves(l, 6)
# define PA	l = moves(l, 7)
# define SS	l = moves(l, 8)
# define RR	l = moves(l, 9)
# define RRR l = moves(l, 10)
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
	int				spot;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;
typedef struct		s_lsts
{
	t_lst			*a;
	t_lst			*b;
	int				mid;
}					t_lsts;
int					check_grps(t_lst *l);
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
int					*tab_creat(int size);
int					tab_cmp_sort(int *tab, t_lst *a);
t_lsts				*spot_srch(t_lsts *l);
t_lsts				*moves(t_lsts *l, int nb);

#endif
