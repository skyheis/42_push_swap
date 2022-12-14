/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:31 by ggiannit          #+#    #+#             */
/*   Updated: 2022/12/14 12:22:50 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

typedef struct s_stmoul
{
	int				num;
	struct s_stmoul	*next;
}	t_stmoul;

/* ---- check_bonus ---- */
int			ft_exec_your_rules(t_stmoul **st_a, t_stmoul **st_b);
int			ft_swappalo(t_stmoul **st_a, t_stmoul **st_b, const char *the_rule);
int			ft_swappalo_continues(t_stmoul **st_a, t_stmoul **st_b,
				const char *the_rule);
int			ft_is_thanos_moul(t_stmoul *st_n, int n);
int			ft_istsize_moul(t_stmoul *st_n);

t_stmoul	*ft_istnew_moul(int atoi);
void		ft_istadd_front_moul(t_stmoul **st_n, t_stmoul *newone);
void		ft_istadd_back_moul(t_stmoul **st_n, t_stmoul *newone);
t_stmoul	*ft_istlast_moul(t_stmoul *st_n);
void		ft_istclear_moul(t_stmoul **st_n);

void		ft_istswap_moul(t_stmoul *st_n);
void		ft_ist_from_to_moul(t_stmoul **from, t_stmoul **to);
void		ft_ist_rot_moul(t_stmoul **st_n);
t_stmoul	*ft_istpre_last_moul(t_stmoul *st_n);
void		ft_ist_rerot_moul(t_stmoul **st_n);

#endif
