/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_your_rules_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:33:33 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/14 12:23:58 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_istsize_moul(t_stmoul *st_n)
{
	int	k;

	k = 0;
	while (st_n)
	{
		st_n = st_n->next;
		k++;
	}
	return (k);
}

int	ft_is_thanos_moul(t_stmoul *st_n, int n)
{
	if (!n)
		n = ft_istsize_moul(st_n);
	while (n-- > 1)
	{
		if (st_n->num > st_n->next->num)
			return (0);
		st_n = st_n->next;
	}
	return (1);
}

int	ft_swappalo(t_stmoul **st_a, t_stmoul **st_b, const char *the_rule)
{
	if (!ft_strncmp(the_rule, "rra\n", 4))
		ft_ist_rerot_moul(st_a);
	else if (!ft_strncmp(the_rule, "rrb\n", 4))
		ft_ist_rerot_moul(st_a);
	else if (!ft_strncmp(the_rule, "rrb\n", 4))
	{
		ft_ist_rerot_moul(st_a);
		ft_ist_rerot_moul(st_b);
	}
	else
	{
		if (!ft_swappalo_continues(st_a, st_b, the_rule))
			return (0);
	}
	return (1);
}

int	ft_swappalo_continues(t_stmoul **st_a, t_stmoul **st_b,
		const char *the_rule)
{
	if (!ft_strncmp(the_rule, "sa\n", 3))
		ft_istswap_moul(*st_a);
	else if (!ft_strncmp(the_rule, "sb\n", 3))
		ft_istswap_moul(*st_b);
	else if (!ft_strncmp(the_rule, "pa\n", 3))
		ft_ist_from_to_moul(st_b, st_a);
	else if (!ft_strncmp(the_rule, "pb\n", 3))
		ft_ist_from_to_moul(st_a, st_b);
	else if (!ft_strncmp(the_rule, "ra\n", 3))
		ft_ist_rot_moul(st_a);
	else if (!ft_strncmp(the_rule, "rb\n", 3))
		ft_ist_rot_moul(st_b);
	else if (!ft_strncmp(the_rule, "rr\n", 3))
	{
		ft_ist_rot_moul(st_a);
		ft_ist_rot_moul(st_b);
	}
	else
		return (0);
	return (1);
}

int	ft_exec_your_rules(t_stmoul **st_a, t_stmoul **st_b)
{
	char	*nline;

	nline = get_next_line(0);
	while (nline)
	{
		if (!ft_swappalo(st_a, st_b, nline))
		{
			ft_printf("Error\n");
			ft_free_null(&nline);
			return (0);
		}
		ft_free_null(&nline);
		nline = get_next_line(0);
	}
	if (!ft_is_thanos_moul(*st_a, 0) && !ft_istsize_moul(*st_b))
	{
		ft_printf("KO\n");
		return (0);
	}
	else
		ft_printf("OK\n");
	ft_istclear_moul(st_a);
	return (1);
}
