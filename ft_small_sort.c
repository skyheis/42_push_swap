/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:40:54 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:09:13 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_div_small(t_istack **st_x, t_istack **st_y, int x_size)
{
	int	n_push;
	int	pivot;

	n_push = 0;
	if (ft_istsize(*st_x) < 4)
		return (n_push);
	pivot = ft_get_pivets(*st_x, x_size);
	while (x_size--)
	{
		if ((*st_x)->num < pivot)
		{
			ft_ist_from_to(st_x, st_y);
			n_push++;
		}
		else
			ft_ist_rot(st_x);
	}
	return (n_push);
}

int	ft_very_small_sort(t_istack **st_x, t_istack **st_y, int n_size)
{
	if (n_size == 3)
	{
		if ((*st_x)->ab == 'a')
			ft_sort_three(st_x, st_y);
		else if ((*st_x)->ab == 'b')
			ft_rev_sort_three(st_x, st_y);
		return (1);
	}
	if ((*st_x)->ab == 'a' && (ft_is_thanos(*st_x, n_size, 0) || n_size < 2))
		return (0);
	else if ((*st_x)->ab == 'b' && (ft_is_thanos(*st_x, n_size, 1)
			|| n_size < 2))
		return (0);
	ft_istswap(*st_x);
	return (1);
}

void	ft_small_sort(t_istack **st_x, t_istack **st_y, int x_size)
{
	int	n_push;

	n_push = 0;
	n_push = ft_div_small(st_x, st_y, x_size);
	if (ft_istsize(*st_x) > 4)
		ft_small_sort(st_x, st_y, x_size - n_push);
	if (n_push > 3)
		ft_small_sort(st_y, st_x, n_push);
	ft_very_small_sort(st_x, st_y, x_size - n_push);
	ft_very_small_sort(st_y, st_x, n_push);
	while (n_push--)
		ft_ist_from_to(st_y, st_x);
}
