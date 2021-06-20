/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:31:49 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 23:00:29 by jisokang         ###   ########.fr       */
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
	t_count		cnt;

	init_count(&cnt);
	while (range-- > 0)
	{
		if (a->head->value > pivot)
			cnt.ra += op_ra(a);
		else
			cnt.pb += op_pb(a, b);
	}
	i = 0;
	if (dlst_size(a->head) != cnt.ra)
	{
		print_check_rra(a, cnt);
		while (i++ < cnt.ra)
			op_rra(a);
	}
	return (cnt);
}

void	push_sort_AtoB(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;

	if (is_out_AtoB(a, b, range) == TRUE)
		return ;
	pivot = get_mid_val(copy_list(a->head), range);
	count = partion_AtoB(a, b, range, pivot);
	print_2_stack(a, b);
	push_sort_AtoB(a, b, count.ra);
	push_sort_BtoA(a, b, count.pb);
	print_2_stack(a, b);
}

static t_count	partion_BtoA(t_stack *a, t_stack *b, int range, int pivot)
{
	int			i;
	t_count		cnt;

	init_count(&cnt);
	while (range-- > 0)
	{
		if (b->head->value > pivot)
			cnt.pa += op_pa(a, b);
		else
			cnt.rb += op_rb(b);
	}
	i = 0;
	if (dlst_size(b->head) != cnt.rb)
	{
		print_check_rrb(b, cnt);
		while (i++ < cnt.rb)
			op_rrb(b);
	}
	return (cnt);
}

void	push_sort_BtoA(t_stack *a, t_stack *b, int range)
{
	int		pivot;
	t_count	count;

	if (is_out_BtoA(a, b, range) == TRUE)
		return ;
	pivot = get_mid_val(copy_list(b->head), range);
	count = partion_BtoA(a, b, range, pivot);
	print_2_stack(a, b);
	push_sort_AtoB(a, b, count.pa);
	push_sort_BtoA(a, b, count.rb);
	print_2_stack(a, b);
}
