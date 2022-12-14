/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:19:33 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/13 21:26:20 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_istswap(t_istack *st_n)
{
	int	tmp;

	if (!st_n || !st_n->next)
		return ;
	tmp = st_n->num;
	st_n->num = st_n->next->num;
	st_n->next->num = tmp;
	if (st_n->ab == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_ist_from_to(t_istack **from, t_istack **to)
{
	t_istack	*node;

	if (!*from)
		return ;
	node = *from;
	if (node->ab == 'a')
	{
		node->ab = 'b';
		ft_printf("pb\n");
	}
	else
	{
		node->ab = 'a';
		ft_printf("pa\n");
	}
	*from = (*from)->next;
	ft_istadd_front(to, node);
}

void	ft_ist_rot(t_istack **st_n)
{
	t_istack	*last;
	t_istack	*head;

	head = *st_n;
	if (head->ab == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	last = ft_istlast(*st_n);
	last->next = *st_n;
	*st_n = (*st_n)->next;
	head->next = NULL;
}

t_istack	*ft_istpre_last(t_istack *st_n)
{
	if (!st_n)
		return (NULL);
	while (st_n->next->next != NULL)
		st_n = st_n->next;
	return (st_n);
}

void	ft_ist_rerot(t_istack **st_n)
{
	t_istack	*new_last;
	t_istack	*new_head;

	new_head = ft_istlast(*st_n);
	if ((*st_n)->ab == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	new_last = ft_istpre_last(*st_n);
	new_head->next = *st_n;
	*st_n = new_head;
	new_last->next = NULL;
}
