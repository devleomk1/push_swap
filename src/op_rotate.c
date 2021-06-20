/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:03 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 01:24:23 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	op_ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra\n");
	return (1);
}

int	op_rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb\n");
	return (1);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr\n");
}
