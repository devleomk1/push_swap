/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:25:46 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 20:42:30 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_lst(t_stack *stack)
{
	int		len;
	t_dlst	*curr;

	len = dlst_size(stack->head);
	curr = stack->head;
	while (len-- > 0)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("||");
}

void	print_stack_vertical(t_stack *stack)
{
	int		i = 0;
	t_dlst	*curr;
	if (stack->head == NULL)
	{
		printf("|---|\n");
	}
	curr = stack->head;
	while (i < dlst_size(stack->head))
	{
		printf("%d[%2d]\n", i, curr->value);
		curr = curr->next;
		i++;
		if (i == dlst_size(stack->head))
			printf("|---|\n");
	}
}

void	print_2_stack(t_stack *stk1, t_stack *stk2)
{
	printf("-----------------------\n");
	printf("Stack A : ");
	print_stack_lst(stk1);
	printf("\n");
	printf("Stack B : ");
	print_stack_lst(stk2);
	printf("\n-----------------------\n");
}

void	print_check_rra(t_stack *a, t_count cnt)
{
	printf("======== print_check_rra ========\n");
	printf("cnt.ra:\t%d\ncnt.pb:\t%d\n""before_rra : ", cnt.ra, cnt.pb);
	print_stack_lst(a);
	printf("\n=================================\n");
}

void	print_check_rrb(t_stack *b, t_count cnt)
{
	printf("=========print_check_rrb=========\n");
	printf("cnt.pa:\t%d\ncnt.rb:\t%d\n""before_rrb : ", cnt.pa, cnt.rb);
	print_stack_lst(b);
	printf("\n=================================\n");
}
