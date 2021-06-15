/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:05:37 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/15 16:31:53 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
}

void	clear_stack(t_stack *stack)
{
	dlst_clear(stack->head);
}

void	push_arg(t_stack *stack, int value)
{
	// push(stack, dlst_new(value));
	dlst_add_back(&stack->head, dlst_new(value));
}

void	push(t_stack *stack, t_dlst *new)
{
	dlst_add_front(&stack->head, new);
	// dlst_add_back(&stack->head, new);
}

t_dlst	*pop_stack(t_stack *stack)
{
	return (dlst_pop(&stack->head));
}

void	push_stack(t_stack *src, t_stack *dst)
{
	if (!src)
		return ;
	if (src->head != NULL)
		push(dst, pop_stack(src));
}

void	swap_stack(t_stack *stack)
{
	if(stack->head != NULL)
		dlst_ndoe_swap_next(&stack->head);
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

