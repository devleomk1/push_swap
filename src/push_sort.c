/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:31:49 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 03:51:45 by jisokang         ###   ########.fr       */
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
	static int	first;
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
	if (first++ != 0)
	{
		while (i++ < cnt.ra)
			op_rra(a);
	}
	return (cnt);
}

void	push_sort_AtoB(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;

	if (out_range3_a(a, b, range) == TRUE)
		return ;
	pivot = get_mid_val(copy_list(a->head), range);
	count = partion_AtoB(a, b, range, pivot);
	push_sort_AtoB(a, b, count.ra);
	push_sort_BtoA(a, b, count.pb);
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
	while (i++ < cnt.rb)
		op_rrb(b);
	return (cnt);
}

void	push_sort_BtoA(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;

	if (out_range3_b(a, b, range) == TRUE)
		return ;
	pivot = get_mid_val(copy_list(b->head), range);
	count = partion_BtoA(a, b, range, pivot);
	push_sort_AtoB(a, b, count.pa);
	push_sort_BtoA(a, b, count.rb);
}
