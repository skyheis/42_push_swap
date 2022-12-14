/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/14 12:11:15 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sorting(t_istack **st_a, t_istack **st_b)
{
	int	stack_size;

	stack_size = ft_istsize(*st_a);
	if (ft_is_thanos(*st_a, stack_size, 0))
		return ;
	else if (stack_size == 2)
		ft_printf("sa\n");
	else if (stack_size == 3)
		ft_sort_three(st_a, st_b);
	else if (stack_size < 7)
		ft_small_sort(st_a, st_b, ft_istsize(*st_a));
	else
		ft_manage_big(st_a, st_b);
}

int	main(int ac, const char **av)
{
	t_istack	*st_a;
	t_istack	*st_b;

	if (ac < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	st_a = ft_make_stack(ac, av);
	st_b = NULL;
	if (!st_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (ft_check_duble_int(st_a))
	{
		ft_istclear(&st_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_sorting(&st_a, &st_b);
	ft_istclear(&st_a);
	return (0);
}
