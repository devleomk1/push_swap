/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:03 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:01:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	op_ra(t_stack *a)
{
	rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	op_rb(t_stack *b)
{
	rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
	return (1);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
