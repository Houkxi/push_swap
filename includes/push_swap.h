/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:36:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/27 19:46:55 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# define SA l = moving(l, 0)
# define RA l = moving(l, 1)
# define RRA l = moving(l, 2)
# define PB	l = moving(l, 3)
# define SB l = moving(l, 4)
# define RB l = moving(l, 5)
# define RRB l = moving(l, 6)
# define PA	l = moving(l, 7)
# define SS	l = moving(l, 8)
# define RR	l = moving(l, 9)
# define RRR l = moving(l, 10)
# define AA l->a->val
# define AB l->a->next->val
# define AZ l->a->prev->val
# define BA l->b->val
# define BB l->b->next->val
# define BZ l->b->prev->val

typedef struct		s_lst
{
	int				data;
	int				val;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;
typedef struct		s_lsts
{
	t_lst			*a;
	t_lst			*b;
	int				mid;
}					t_lsts;
typedef struct		s_grp
{
	int				group;
	struct	s_grp	*next;
}					t_grp;
int					data_check(t_lst *lst, int curr);
void				ft_lst_print_cir(t_lst **alst, int nb_lst, int add);

int					ft_are_sorted_a(t_lst *lst);
int					ft_solve_a(t_lsts *data);
int					ft_move_on_a(t_lsts *data, int middle, int *max);
int					ft_move_on_b(t_lsts *data, int middle, int max);
int					loop_spot(t_lst *a, int sv);
t_lst				*change_lst(t_lst *a);
int					ft_quicksort(t_lsts *data);
t_lsts				*moving(t_lsts *l, int nb);
int					ft_find_middle(t_lst *lst, int k, int len);

t_lst				*init_pars(char **ac, int av);
t_lst				*lst_init(long nbr);
void				lst_circular(t_lst **lst, t_lst *new);
int					ft_lstlen(t_lst *lst);
t_lsts				*push_a(t_lsts *l);
t_lsts				*push_b(t_lsts *l);
t_lsts				*push_on_a(t_lsts *l, int mid, int *ct);
t_lsts				*push_on_b(t_lsts *l, int mid, int *ct);
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

#endif
