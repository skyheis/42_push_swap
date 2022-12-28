/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:40:54 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/20 11:10:11 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_div_small(t_istack **st_x, t_istack **st_y, int x_size)
{
	int	n_push;
	int	pivot;

	n_push = 0;
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

void	ft_small_sort(t_istack **st_x, t_istack **st_y, int x_size)
{
	int	n_push;

	n_push = ft_div_small(st_x, st_y, x_size);
	if (x_size - n_push == 3)
		ft_sort_three(st_x, st_y);
	else if ((*st_x)->num > (*st_x)->next->num)
		ft_istswap(*st_x);
	if ((*st_y)->num < (*st_y)->next->num)
		ft_istswap(*st_y);
	while (n_push--)
		ft_ist_from_to(st_y, st_x);
}
