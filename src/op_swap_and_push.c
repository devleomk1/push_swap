/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:30:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/29 19:56:15 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void	op_sa(t_stack *a, t_stack *b)
{
	swap_stack(a);
	printf("sa\n");
}

void	op_sb(t_stack *a, t_stack *b)
{
	swap_stack(b);
	printf("sb\n");
}

void	op_ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	printf("ss\n");
}

void	op_pa(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	printf("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	printf("pb\n");
}

