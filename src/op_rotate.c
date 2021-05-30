/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:03 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/30 22:26:28 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra\n");
}

void	op_rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr\n");
}
