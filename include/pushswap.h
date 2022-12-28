/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:31 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/20 11:11:07 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "pushswap_bonus.h"

typedef struct s_istack
{
	int				num;
	char			ab;
	struct s_istack	*next;
}	t_istack;

/* ft_check_n_make */
int			ft_check_duble_int(t_istack *st_n);
int			ft_check_str(const char *avacu);
t_istack	*ft_make_stack(int ac, const char **av);
int			ft_atoi_check(int atoi, const char *str);

/* ft_algo_utils */
int			ft_is_thanos(t_istack *st_n, int n, int rev);
int			ft_get_pivets(t_istack *st_n, int n_size);
int			ft_get_pivets_bigsort(t_istack *st_n, int n_size,
				int total_element, int is_b);

/* ft_istack */
int			ft_istsize(t_istack *st_n);
void		ft_istadd_front(t_istack **st_n, t_istack *newone);
void		ft_istadd_back(t_istack **st_n, t_istack *newone);
t_istack	*ft_istlast(t_istack *st_n);
t_istack	*ft_istnew(int atoi, char ab);

/* ft_istack_utils */
void		ft_istclear(t_istack **st_n);
void		ft_istdelone(t_istack **st_n);

/* ft_stackmove */
void		ft_istswap(t_istack *st_n);
void		ft_ist_from_to(t_istack **from, t_istack **to);
void		ft_ist_rot(t_istack **st_n);
t_istack	*ft_istpre_last(t_istack *st_n);
void		ft_ist_rerot(t_istack **st_n);

/* ft_small_sort */
void		ft_small_sort(t_istack **st_a, t_istack **st_b, int n_size);

/* ft_sort_three */
void		ft_sort_three(t_istack **st_a, t_istack **st_b);
//void		ft_rev_sort_three(t_istack **st_a, t_istack **st_b);

/* ft_biggest_sort */
void		ft_biggest_sort(t_istack **st_a, t_istack **st_b,
				t_istack **st_piv);
void		ft_manage_big(t_istack **st_a, t_istack **st_b);
void		ft_reverse_push(t_istack **st_a, t_istack **st_b, int piv,
				int *count_stack);
void		ft_biggest_push(t_istack **st_a, t_istack **st_b,
				int piv, int *count_stack);

/* ft_biggest_sort_utils */
int			ft_findmax(t_istack *st_n);
int			ft_findmin(t_istack *st_n, t_istack *st_o);
int			ft_all_over_pivot(t_istack *st_n, int pivot);
int			ft_ministack_size(t_istack *st_b, t_istack **st_piv);
void		ft_bottom_ministack(t_istack **st_a, t_istack **st_b);

/* bubbling */
void		ft_bubblesort(int	*tab, int size);
void		ft_bubblesort_istack(t_istack	**st_tab);

/* ft_debugging */
void		ft_print_stack(t_istack *st_a, t_istack *st_b);

#endif
