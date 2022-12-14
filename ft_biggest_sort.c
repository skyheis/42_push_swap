/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:26:13 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:48:47 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_biggest_sort(t_istack **st_a, t_istack **st_b,
		t_istack **st_piv)
{
	int	pivot;
	int	b_piv;
	int	n_size;

	n_size = ft_istsize(*st_a);
	if (n_size < 6)
		return ;
	pivot = ft_get_pivets_bigsort(*st_a, n_size,
			ft_istsize(*st_a) + ft_istsize(*st_b), 0);
	b_piv = ft_get_pivets_bigsort(*st_a, n_size,
			ft_istsize(*st_a) + ft_istsize(*st_b), 1);
	ft_istadd_front(st_piv, ft_istnew(pivot, '\0'));
	ft_istadd_front(st_piv, ft_istnew(b_piv, '\0'));
	while (ft_all_over_pivot(*st_a, pivot))
	{
		if ((*st_a)->num < pivot)
		{
			ft_ist_from_to(st_a, st_b);
			if ((*st_b)->num < b_piv)
				ft_ist_rot(st_b);
		}
		else
			ft_ist_rot(st_a);
	}
	ft_biggest_sort(st_a, st_b, st_piv);
}

void	ft_reverse_push_utils(t_istack **st_a, t_istack **st_b, int piv,
		int *count_stack)
{
	int			max_num;
	t_istack	*a_last;

	max_num = ft_findmax(*st_a);
	a_last = ft_istlast(*st_a);
	if ((*st_b)->num == ft_findmax(*st_b))
	{
		ft_ist_from_to(st_b, st_a);
		ft_bottom_ministack(st_a, st_b);
		*count_stack = *count_stack - 1;
		if (*count_stack)
			ft_ist_rerot(st_b);
	}
	else if (a_last->num == max_num || a_last->num < (*st_b)->num)
	{
		ft_ist_from_to(st_b, st_a);
		ft_ist_rot(st_a);
		*count_stack = *count_stack - 1;
		if (ft_istlast(*st_b)->num >= piv && (*st_b)->num < piv)
			ft_ist_rerot(st_b);
	}
	else
		ft_ist_rerot(st_b);
}

void	ft_reverse_push(t_istack **st_a, t_istack **st_b, int piv,
		int *count_stack)
{
	ft_ist_rerot(st_b);
	while (*count_stack)
	{
		ft_reverse_push_utils(st_a, st_b, piv, count_stack);
		if (*count_stack && (*st_b)->num < piv)
		{
			ft_ist_rot(st_b);
			ft_biggest_push(st_a, st_b, piv, count_stack);
		}
	}
}

void	ft_biggest_push(t_istack **st_a, t_istack **st_b,
		int piv, int *count_stack)
{
	t_istack	*a_last;
	int			max_num;

	max_num = ft_findmax(*st_a);
	while (*count_stack)
	{
		a_last = ft_istlast(*st_a);
		if ((*st_b)->num == ft_findmax(*st_b))
		{
			ft_ist_from_to(st_b, st_a);
			ft_bottom_ministack(st_a, st_b);
			*count_stack = *count_stack - 1;
		}
		else if (a_last->num == max_num || a_last->num < (*st_b)->num)
		{
			ft_ist_from_to(st_b, st_a);
			ft_ist_rot(st_a);
			*count_stack = *count_stack - 1;
		}
		else
			ft_ist_rot(st_b);
		if (*count_stack && *st_b && (*st_b)->num < piv)
			ft_reverse_push(st_a, st_b, piv, count_stack);
	}
}

void	ft_manage_big(t_istack **st_a, t_istack **st_b)
{
	t_istack	*st_piv;
	int			count_stack;

	st_piv = NULL;
	ft_biggest_sort(st_a, st_b, &st_piv);
	ft_small_sort(st_a, st_b, ft_istsize(*st_a));
	ft_bubblesort_istack(&st_piv);
	while (st_piv)
	{
		ft_istdelone(&st_piv);
		if (!st_piv)
			break ;
		count_stack = ft_ministack_size(*st_b, &st_piv);
		ft_biggest_push(st_a, st_b, st_piv->num, &count_stack);
		ft_istdelone(&st_piv);
		if (!st_piv)
			break ;
		count_stack = ft_ministack_size(*st_b, &st_piv);
		ft_reverse_push(st_a, st_b, st_piv->num, &count_stack);
	}
	count_stack = ft_istsize(*st_b);
	ft_biggest_push(st_a, st_b, ft_findmin(*st_a, *st_b), &count_stack);
}
