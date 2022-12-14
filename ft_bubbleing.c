/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubbleing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:50:17 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:06:10 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_bubblesort(int *tab, int size)
{
	int	x;
	int	tmp;
	int	did_swap;

	did_swap = 1;
	while (did_swap)
	{
		x = 0;
		did_swap = 0;
		while (x < size - 1)
		{
			if (tab[x] > tab[x + 1])
			{
				tmp = tab[x + 1];
				tab[x + 1] = tab[x];
				tab[x] = tmp;
				did_swap = 1;
			}
			x++;
		}
	}
}

void	ft_bubblesort_istack(t_istack **st_tab)
{
	t_istack	*head;
	int			tmp;
	int			did_swap;

	did_swap = 1;
	head = (*st_tab);
	while (did_swap)
	{
		did_swap = 0;
		while ((*st_tab)->next)
		{
			if ((*st_tab)->num < (*st_tab)->next->num)
			{
				tmp = (*st_tab)->next->num;
				(*st_tab)->next->num = (*st_tab)->num;
				(*st_tab)->num = tmp;
				did_swap = 1;
			}
			(*st_tab) = (*st_tab)->next;
		}
		(*st_tab) = head;
	}
}
