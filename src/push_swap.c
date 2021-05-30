/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/30 22:23:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
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
		printf("|%3d|\n", curr->value);
		curr = curr->next;
		i++;
		if (i == dlst_size(stack->head))
			printf("|---|\n");
	}
}

void	push_swap(void)
{

}
//피봇을 찾기 위해 우선 정렬을 해야한다.

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stk_a;
	t_stack	stk_b;

	if (argc < 2)
		return (0);
	init_stack(&stk_b);
	i = 1;
	while (argv[i] != NULL)
		push_new(&stk_a, ft_atoi(argv[i++]));
	print_stack(&stk_a);
	printf("\n\n");
	print_stack(&stk_b);

	//---------------------
	op_ra(&stk_a);
	print_stack(&stk_a);
	printf("\n\n");
	print_stack(&stk_b);

	//---------------------
	op_pb(&stk_a, &stk_b);
	print_stack(&stk_a);
	printf("\n\n");
	print_stack(&stk_b);
	return (0);
}
