/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:31:49 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/18 21:53:35 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_count(t_count *cnt)
{
	cnt->ra = 0;
	cnt->pb = 0;
	cnt->rb = 0;
	cnt->pa = 0;
}

static t_count	partion_AtoB(t_stack *a, t_stack *b, int range, int pivot)
{
	int			i;
	// static int	first;
	t_count		cnt;

	init_count(&cnt);
	while (range-- > 0)
	{
		if (a->head->value > pivot)
		{
			op_ra(a);
			cnt.ra++;
		}
		else
		{
			op_pb(a, b);
			cnt.pb++;
		}
	}
	i = 0;
	/*
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("cnt.ra:%d \tcnt.pb:%d\n", cnt.ra, cnt.pb);
	printf("before_rra :\t");
	print_stack_lst(a);
	printf("\n");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-**-*-*-*-*-*-*-*\n");
	*/
	// if (first++ != 0)
	if (dlst_size(a->head) != cnt.ra)
	{
		while (i++ < cnt.ra)
		{
			// printf("-------");
			op_rra(a);
			// printf("\t\t");
			// print_stack_lst(a);
			// printf("\n");
		}
	}
	return (cnt);
}

void	push_sort_AtoB(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;
	// printf("A->B\n");
	if (out_range3_a(a, b, range) == TRUE)
		return ;
	pivot = get_mid_val(copy_list(a->head), range);
	count = partion_AtoB(a, b, range, pivot);
	// print_2_stack(a, b);
	push_sort_AtoB(a, b, count.ra);
	push_sort_BtoA(a, b, count.pb);
	// print_2_stack(a, b);
}

static t_count	partion_BtoA(t_stack *a, t_stack *b, int range, int pivot)
{
	int			i;
	t_count		cnt;

	init_count(&cnt);
	while (range-- > 0)
	{
		if (b->head->value > pivot)
		{
			op_pa(a, b);
			cnt.pa++;
		}
		else
		{
			op_rb(b);
			cnt.rb++;
		}
	}
	i = 0;
/* 	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("cnt.pa:%d \tcnt.rb:%d\n", cnt.pa, cnt.rb);
	printf("before_rrb : ");
	print_stack_lst(b);
	printf("\n");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"); */
	if (dlst_size(b->head) != cnt.rb)
		while (i++ < cnt.rb)
		{
			// printf("--------");
			op_rrb(b);
			// print_stack_lst(b);
			// printf("\n");
		}
	return (cnt);
}

void	push_sort_BtoA(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;

	if (out_range3_b(a, b, range) == TRUE)
		return ;
	// printf("B->A\n");
	pivot = get_mid_val(copy_list(b->head), range);
	count = partion_BtoA(a, b, range, pivot);
	// print_2_stack(a, b);
	push_sort_AtoB(a, b, count.pa);
	push_sort_BtoA(a, b, count.rb);
	// print_2_stack(a, b);
}
