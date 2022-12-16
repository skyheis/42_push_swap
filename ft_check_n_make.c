/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_make.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:10:25 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/15 15:48:20 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_check_duble_int(t_istack *st_n)
{
	t_istack	*tmp;

	tmp = NULL;
	while (st_n->next)
	{
		tmp = st_n->next;
		while (tmp)
		{
			if (st_n->num == tmp->num)
				return (1);
			tmp = tmp->next;
		}
		st_n = st_n->next;
	}
	return (0);
}

int	ft_check_str(const char *avac)
{
	int	k;

	k = 0;
	while (avac[k] == 32 || (avac[k] >= 9 && avac[k] <= 13))
		k++;
	if (avac[k] == '-' || avac[k] == '+')
		k++;
	if (!ft_isdigit(avac[k]))
		return (0);
	while (avac[k] >= '0' && avac[k] <= '9')
		k++;
	if (avac[k] != '\0')
		return (0);
	return (1);
}

int	ft_atoi_check(int atoi, const char *str)
{
	int	k;
	int	posit;

	if (ft_strchr(str, '-') && atoi > 0)
		return (0);
	else if (!ft_strchr(str, '-') && atoi < 0)
		return (0);
	k = ft_strlen(str);
	while (--k >= 0 && ft_isdigit(str[k]))
	{
		posit = atoi % 10;
		if (posit < 0)
			posit *= -1;
		if (str[k] != (posit + 48))
			return (0);
		atoi /= 10;
	}
	return (1);
}

t_istack	*ft_make_stack(int ac, const char **av)
{
	t_istack	*st_a;
	int			atoi;

	st_a = NULL;
	while (ac-- > 1)
	{
		if (!ft_check_str(av[ac]))
		{
			ft_istclear(&st_a);
			return (NULL);
		}
		atoi = ft_atoi(av[ac]);
		if (!ft_atoi_check(atoi, av[ac]))
			return (NULL);
		ft_istadd_front(&st_a, ft_istnew(atoi, 'a'));
	}
	return (st_a);
}
