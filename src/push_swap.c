/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/05 00:37:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_lst(t_stack *stack)
{
	int		len;
	t_dlst	*curr;

	len = dlst_size(stack->head);
	curr = stack->head;
	printf("[H] ");
	while (len-- > 0)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("[T] ");
}

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
		printf("%d[%2d]\n", i, curr->value);
		curr = curr->next;
		i++;
		if (i == dlst_size(stack->head))
			printf("|---|\n");
	}
}

void	print_2_stack(t_stack *stk1, t_stack *stk2)
{
	printf("Stack A : ");
	//print_stack(stk1);
	print_stack_lst(stk1);
	printf("\n\n");
	printf("Stack B : ");
	//print_stack(stk2);
	print_stack_lst(stk2);
	printf("\n");
}

void	swap_dlst_xy(t_stack *stack, size_t x, size_t y)
{
	t_dlst	*lst_x;
	t_dlst	*lst_y;
	if (stack == NULL || x == y)
		return ;
	lst_x = dlst_count(stack->head, x);
	lst_y = dlst_count(stack->head, y);
	if (lst_x == NULL || lst_y == NULL)
		return ;
	dlst_node_swap(lst_x, lst_y);
	printf("stack의 %zu번째 노드와 %zu번째 노드를 swap했습니다.\n", x, y);
}

void	push_swap(void)
{

}
//최적 피봇을 찾기 위해 우선 정렬을 해야한다.

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
	print_2_stack(&stk_a, &stk_b);

	// op_ra(&stk_a);
	// print_2_stack(&stk_a, &stk_b);
	// op_pb(&stk_a, &stk_b);
	// print_2_stack(&stk_a, &stk_b);

	// swap_dlst_xy(&stk_a, 0, 1);
	// print_2_stack(&stk_a, &stk_b);

	// op_sa(&stk_a);
	// print_2_stack(&stk_a, &stk_b);

	quick_sort(stk_a.head);
	print_2_stack(&stk_a, &stk_b);

	return (0);
}
