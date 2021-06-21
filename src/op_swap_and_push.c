/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:30:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:04:59 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack *b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_putstr_fd("ss\n", 1);
}

int	op_pa(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	op_pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_putstr_fd("pb\n", 1);
	return (1);
}

