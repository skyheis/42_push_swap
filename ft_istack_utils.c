/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:02:13 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:05:04 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_istdelone(t_istack **st_n)
{
	t_istack	*tmp;

	tmp = *st_n;
	(*st_n) = (*st_n)->next;
	free(tmp);
}

void	ft_istclear(t_istack **st_n)
{
	t_istack	*tmp;

	tmp = NULL;
	while (*st_n)
	{
		tmp = (*st_n)->next;
		free(*st_n);
		(*st_n) = tmp;
	}
}
