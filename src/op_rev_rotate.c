/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:27 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 10:03:31 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rra(t_stack *a)
{
	rev_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack *b)
{
	rev_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
