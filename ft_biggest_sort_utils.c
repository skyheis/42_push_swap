/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_sort_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:27:15 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:31:24 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_findmax(t_istack *st_n)
{
	int	max_num;

	max_num = -2147483648;
	while (st_n)
	{
		if (st_n->num > max_num)
			max_num = st_n->num;
		st_n = st_n->next;
	}
	return (max_num);
}

int	ft_findmin(t_istack *st_n, t_istack *st_o)
{
	int	min_num;

	min_num = 2147483647;
	while (st_n)
	{
		if (st_n->num < min_num)
			min_num = st_n->num;
		st_n = st_n->next;
	}
	while (st_o)
	{
		if (st_o->num < min_num)
			min_num = st_o->num;
		st_o = st_o->next;
	}
	return (min_num);
}

int	ft_all_over_pivot(t_istack *st_n, int pivot)
{
	while (st_n)
	{
		if (st_n->num < pivot)
			return (1);
		st_n = st_n->next;
	}
	return (0);
}

int	ft_ministack_size(t_istack *st_b, t_istack **st_piv)
{
	int	count_stack;

	count_stack = 0;
	while (st_b)
	{
		if (st_b->num >= (*st_piv)->num)
			count_stack++;
		st_b = st_b->next;
	}
	return (count_stack);
}

void	ft_bottom_ministack(t_istack **st_a, t_istack **st_b)
{
	t_istack	*tmp;

	tmp = ft_istlast(*st_a);
	if (tmp->num > ft_findmax(*st_b) && tmp->num != ft_findmax(*st_a))
	{
		ft_ist_rerot(st_a);
		ft_bottom_ministack(st_a, st_b);
	}
}
