/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/11 20:41:38 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_lst(t_stack *stack)
{
	int		len;
	t_dlst	*curr;

	len = dlst_size(stack->head);
	curr = stack->head;
	// printf("[H] ");
	while (len-- > 0)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("||");
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
	printf("-----------------------\nStack A : ");
	// print_stack(stk1);
	print_stack_lst(stk1);
	printf("\n");
	printf("Stack B : ");
	// print_stack(stk2);
	print_stack_lst(stk2);
	printf("\n-----------------------\n");
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

void	push_swap_AtoB(t_stack *a, t_stack *b, unsigned int range, int pivot)
{
	int		ra_count;
	int		pb_count;

	ra_count = 0;
	pb_count = 0;
	while(range > 0)
	{
		if(a->head->value > pivot)
		{
			op_ra(a);
			ra_count++;
		}
		else
		{
			op_pb(a, b);
			pb_count++;
		}
		range--;
	}
	print_2_stack(a, b);
	while(ra_count > 0)
	{
		op_rra(a);
		ra_count--;
	}
}

void	push_swap_BtoA(t_stack *a, t_stack *b, unsigned int range, int pivot)
{
	int		rb_count;
	int		pa_count;

	rb_count = 0;
	pa_count = 0;
	while(range > 0)
	{
		if(b->head->value > pivot)
		{
			op_rb(b);
			rb_count++;
		}
		else
		{
			op_pa(a, b);
			pa_count++;
		}
		range--;
	}
	print_2_stack(a, b);
	while(rb_count > 0)
	{
		op_rrb(b);
		rb_count--;
	}
}

t_dlst	*dlst_new_copy(t_dlst *lst)
{
	t_dlst *new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
	{
		printf("MALLOC_ERROR\n");
		return (NULL);
	}
	new->value = lst->value;
	return (new);
}
t_dlst	*dlst_copy_lst(t_dlst *lst)
{
	t_dlst	*curr;
	t_dlst	*tmp;
	t_dlst	*tmp2;

	curr = lst;
	tmp2 = lst;
	while (curr->next != tmp2)
	{
		tmp = dlst_new_copy(curr);
		dlst_add_back(&lst, tmp);
		curr = curr->next;
	}
	return (tmp);
}

void	dlst_print(t_dlst *head)
{
	t_dlst *curr;

	curr = head;
	while (curr->next != head)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("%d ", curr->value);
	printf("\n");

}

t_dlst	*copy_list(t_dlst *lst)
{
	t_dlst	*curr;
	t_dlst	*cpy = NULL;

	curr = lst;
	while (curr->next != lst)
	{
		dlst_add_back(&cpy, dlst_new(curr->value));
		curr = curr->next;
	}
	dlst_add_back(&cpy, dlst_new(curr->value));
	return (cpy);

}

int	main(int argc, char **argv)
{
	t_stack	stk_a;
	t_stack	stk_b;
	t_dlst	*tmp;

	init_push_swap(&stk_a, &stk_b, argc, argv);
	print_2_stack(&stk_a, &stk_b);
	//print_sort_status(stk_a.head);

	tmp = copy_list(stk_a.head);
	dlst_print(tmp);
	quick_sort(tmp);
	// quick_sort(stk_a.head);
	// push_swap_AtoB(&stk_a, &stk_b, 20, 11);
	// push_swap_BtoA(&stk_a, &stk_b, 10, 6);
	dlst_print(tmp);
	print_2_stack(&stk_a, &stk_b);
	//print_sort_status(stk_a.head);

	return (0);
}
