/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:57:12 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:05:12 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_arg(t_stack *stack, int value)
{
	dlst_add_back(&stack->head, dlst_new(value));
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
	if (!src)
		return ;
	if (src->head != NULL)
		push(dst, pop_stack(src));
}
