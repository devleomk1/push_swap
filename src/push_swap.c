/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 03:55:42 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	out_range3_a(t_stack *a, t_stack *b, int range)
{
	int	box_a[3];

	if (range <= 1)
		return (1);
	else if (range == 2)
	{
		if (a->head->value > a->head->next->value)
			op_sa(a);
		return (1);
	}
	else if (range == 3)
	{
		box_a[0] = a->head->value;
		box_a[1] = a->head->next->value;
		box_a[2] = a->head->next->next->value;
		if (box_a[0] < box_a[2] && box_a[2] < box_a[1])
			case3a_021(a, b);
		else if (box_a[1] < box_a[0] && box_a[0] < box_a[2])
			op_sa(a);
		else if (box_a[1] < box_a[2] && box_a[2] < box_a[0])
			case3a_201(a, b);
		else if (box_a[2] < box_a[0] && box_a[0] < box_a[1])
			case3a_120(a, b);
		else if (box_a[2] < box_a[1] && box_a[1] < box_a[0])
			case3a_210(a, b);
		return (1);
	}
	return (0);
}

int	out_range3_b(t_stack *a, t_stack *b, int range)
{
	int		val[3];

	if (range <= 1)
		return (1);
	else if (range == 2)
	{
		if (b->head->value < b->head->next->value)
			op_sb(b);
		op_pa(a, b);
		op_pa(a, b);
		return (1);
	}
	else if (range == 3)
	{
		val[0] = b->head->value;
		val[1] = b->head->next->value;
		val[2] = b->head->next->next->value;
		if (val[0] < val[1] && val[1] < val[2])
			case3b_012(a, b);
		if (val[0] < val[2] && val[2] < val[1])
			case3b_021(a, b);
		else if (val[1] < val[0] && val[0] < val[2])
			case3b_102(a, b);
		else if (val[1] < val[2] && val[2] < val[0])
			case3b_201(a, b);
		else if (val[2] < val[0] && val[0] < val[1])
			case3b_120(a, b);
		else if (val[2] < val[1] && val[1] < val[0])
		{
			op_pa(a, b);
			op_pa(a, b);
			op_pa(a, b);
		}
		return (1);
	}
	return (0);
}
void	push_swap(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		error_exit("Argument Error");
	else if(argc == 2)
		exit(0);
	init_stack(a);
	init_stack(b);
	i = 1;
	while (argv[i] != NULL)
		push_arg(a, ft_atoi(argv[i++]));
	stack_status_check(a);
	push_sort_AtoB(a, b, dlst_size(a->head));
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	push_swap(&a, &b, argc, argv);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
