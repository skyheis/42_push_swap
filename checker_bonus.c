/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/14 12:25:09 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stmoul	*ft_make_stack_moul(int ac, const char **av)
{
	t_stmoul	*st_a;
	int			atoi;

	st_a = NULL;
	while (ac-- > 1)
	{
		if (!ft_check_str(av[ac]))
			return (NULL);
		atoi = ft_atoi(av[ac]);
		ft_istadd_front_moul(&st_a, ft_istnew_moul(atoi));
	}
	return (st_a);
}

int	main(int ac, const char **av)
{
	t_stmoul	*st_a;
	t_stmoul	*st_b;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	st_a = ft_make_stack_moul(ac, av);
	st_b = NULL;
	if (!st_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ft_check_duble_int((t_istack *)st_a))
	{
		ft_printf("Error\n");
		ft_istclear_moul(&st_a);
		return (1);
	}
	if (!ft_exec_your_rules(&st_a, &st_b))
		return (1);
	return (0);
}
