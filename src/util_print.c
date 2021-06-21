/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:25:46 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:32:36 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_dlst	*curr;

	if (stack->head == NULL)
	{
		ft_putstr_fd("||", 1);
		return ;
	}
	curr = stack->head;
	while (curr->next != stack->head)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("%d ||", curr->value);
}

void	dlst_print(t_dlst *head)
{
	t_dlst	*curr;

	if (head == NULL)
		return ;
	curr = head;
	while (curr->next != head)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("%d \n", curr->value);
}

void	print_stack_all(t_stack *stk1, t_stack *stk2, int opt)
{
	if (opt)
	{
		ft_printf("-----------------------\nA : ");
		print_stack(stk1);
		ft_printf("\nB : ");
		print_stack(stk2);
		ft_printf("\n-----------------------\n");
	}
}
