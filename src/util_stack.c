/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:05:37 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/30 22:26:28 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	//stack->tail = NULL;
}

void	push_new(t_stack *stack, int value)
{

	push(stack, dlst_new(value));
}

void	push(t_stack *stack, t_dlst *new)
{
	dlst_add_front(&stack->head, new);
}

t_dlst	*pop_stack(t_stack *stack)
{
	return (dlst_pop(&stack->head));
}

void	push_stack(t_stack *src, t_stack *dst)
{
	if (src->head != NULL)
		push(dst, pop_stack(src));
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if(stack->head != NULL)
	{
		tmp = stack->head->value;
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp;
	}
}

void	rotate_stack(t_stack *stack)
{
	if (stack != NULL || stack->head == stack->head->prev)
		stack->head = stack->head->next;
}

void	rotate_rotate_stack(t_stack *stk1, t_stack *stk2)
{
	rotate_stack(stk1);
	rotate_stack(stk2);
}

void	rev_rotate_stack(t_stack *stack)
{
	if (stack != NULL || stack->head == stack->head->prev)
		stack->head = stack->head->prev;
}

void	rev_rotate_rotate_stack(t_stack *stk1, t_stack *stk2)
{
	rev_rotate_stack(stk1);
	rev_rotate_stack(stk2);
}
