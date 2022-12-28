/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:02:06 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/20 11:11:24 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_istack **st_a, t_istack **st_b)
{
	if (ft_is_thanos(*st_a, 3, 0))
		return ;
	if ((*st_a)->num < (*st_a)->next->num
		&& (*st_a)->next->num > (*st_a)->next->next->num
		&& (*st_a)->num < (*st_a)->next->next->num)
	{
		ft_ist_from_to(st_a, st_b);
		ft_istswap(*st_a);
		ft_ist_from_to(st_b, st_a);
	}
	else if ((*st_a)->num > (*st_a)->next->num
		&& (*st_a)->num < (*st_a)->next->next->num)
		ft_istswap(*st_a);
	else if ((*st_a)->num > (*st_a)->next->num
		&& (*st_a)->num > (*st_a)->next->next->num
		&& (*st_a)->next->num < (*st_a)->next->next->num)
		ft_ist_rot(st_a);
	else if ((*st_a)->num < (*st_a)->next->num)
		ft_ist_rerot(st_a);
	else
	{
		ft_istswap(*st_a);
		ft_ist_rerot(st_a);
	}
}

/*void	ft_rev_sort_three(t_istack **st_a, t_istack **st_b)
{
	if (ft_is_thanos(*st_a, 3, 1))
		return ;
	if (ft_is_thanos(*st_a, 3, 0))
	{
		ft_istswap(*st_a);
		ft_ist_rerot(st_a);
	}
	else if ((*st_a)->num < (*st_a)->next->num
		&& (*st_a)->next->num > (*st_a)->next->next->num
		&& (*st_a)->num < (*st_a)->next->next->num)
		ft_ist_rot(st_a);
	else if ((*st_a)->num > (*st_a)->next->num
		&& (*st_a)->num < (*st_a)->next->next->num)
		ft_ist_rerot(st_a);
	else if ((*st_a)->num > (*st_a)->next->num
		&& (*st_a)->num > (*st_a)->next->next->num
		&& (*st_a)->next->num < (*st_a)->next->next->num)
	{
		ft_ist_from_to(st_a, st_b);
		ft_istswap(*st_a);
		ft_ist_from_to(st_b, st_a);
	}
	else if ((*st_a)->num < (*st_a)->next->num)
		ft_istswap(*st_a);
}*/
