/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:03 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/29 19:58:23 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_ra(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	printf("ra\n");
}

void	op_rb(t_stack *a, t_stack *b)
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
