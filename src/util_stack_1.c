/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:05:37 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:33:34 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_stack(t_stack *stack)
{
	if (stack->head != NULL)
		dlst_node_swap_next(&stack->head);
}

void	rotate_stack(t_stack *stack)
{
	if (stack != NULL || stack->head == stack->head->prev)
		stack->head = stack->head->next;
}

void	rev_rotate_stack(t_stack *stack)
{
	if (stack != NULL || stack->head == stack->head->prev)
		stack->head = stack->head->prev;
}
