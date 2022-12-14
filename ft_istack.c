/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:04:33 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:04:50 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_istsize(t_istack *st_n)
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

t_istack	*ft_istlast(t_istack *st_n)
{
	if (st_n == NULL)
		return (st_n);
	while (st_n->next != NULL)
		st_n = st_n->next;
	return (st_n);
}

void	ft_istadd_back(t_istack **st_n, t_istack *newone)
{
	t_istack	*last_node;

	if (*st_n == NULL)
		*st_n = newone;
	else
	{
		last_node = ft_istlast(*st_n);
		last_node->next = newone;
	}
}

void	ft_istadd_front(t_istack **st_n, t_istack *newone)
{
	newone->next = *st_n;
	*st_n = newone;
}

t_istack	*ft_istnew(int atoi, char ab)
{
	t_istack	*newone;

	newone = (t_istack *) malloc(sizeof(t_istack));
	if (!newone)
		return (NULL);
	newone->num = atoi;
	newone->ab = ab;
	newone->next = NULL;
	return (newone);
}
