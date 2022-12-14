/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugging.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:02:43 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:18:02 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_print_stack(t_istack *st_a, t_istack *st_b)
{
	while (st_a || st_b)
	{
		if (st_a)
		{
			ft_printf("%4d", st_a->num);
			st_a = st_a->next;
		}
		else
			ft_printf("    ");
		ft_printf("  ");
		if (st_b)
		{
			ft_printf("%4d\n", st_b->num);
			st_b = st_b->next;
		}
		else
			ft_printf("    \n");
	}
}
