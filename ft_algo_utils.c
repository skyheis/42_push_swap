/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:28:11 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:00:52 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_thanos(t_istack *st_n, int n, int rev)
{
	if (!n)
		n = ft_istsize(st_n);
	while (n-- > 1)
	{
		if (!rev && st_n->num > st_n->next->num)
			return (0);
		if (rev && st_n->num < st_n->next->num)
			return (0);
		st_n = st_n->next;
	}
	return (1);
}

int	*ft_sorted_malloc(t_istack *st_n, int n_size)
{
	int	*x;
	int	k;

	k = 0;
	x = (int *) malloc(n_size * sizeof(int));
	if (!x)
		return (NULL);
	while (st_n)
	{
		x[k++] = st_n->num;
		st_n = st_n->next;
	}
	return (x);
}

int	ft_get_pivets(t_istack *st_n, int n_size)
{
	int	*sorted;
	int	pivet;

	if (!n_size)
		n_size = ft_istsize(st_n);
	sorted = ft_sorted_malloc(st_n, n_size);
	ft_bubblesort(sorted, n_size);
	n_size = n_size >> 1;
	pivet = sorted[n_size];
	free(sorted);
	return (pivet);
}

int	ft_get_pivets_bigsort(t_istack *st_n, int n_size, int total_element,
		int is_b)
{
	int	*sorted;
	int	pivet;

	if (!n_size)
		n_size = ft_istsize(st_n);
	(void) total_element;
	sorted = ft_sorted_malloc(st_n, n_size);
	ft_bubblesort(sorted, n_size);
	if (total_element < 150)
		n_size = n_size / 5 * 2;
	else
		n_size = n_size >> 2;
	if (is_b)
		pivet = sorted[n_size >> 1];
	else
		pivet = sorted[n_size];
	free(sorted);
	return (pivet);
}
