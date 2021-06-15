/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:53:54 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/15 23:07:28 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		case3b_012(t_stack *a, t_stack *b)
{
	if (dlst_size(b->head) == 3)
	{
		op_rb(b);
		op_sb(b);
		op_pa(a, b);
		op_pa(a, b);
		op_pa(a, b);
		return ;
	}
	op_rb(b);
	op_pa(a, b);
	op_pa(a, b);
	op_rrb(b);
	op_sa(a);
	op_pa(a, b);
}

void		case3b_021(t_stack *a, t_stack *b)
{
	if (dlst_size(b->head) == 3)
	{
		op_rb(b);
		op_pa(a, b);
		op_pa(a, b);
		op_pa(a, b);
		return ;
	}
	op_rb(b);
	op_pa(a, b);
	op_pa(a, b);
	op_rrb(b);
	op_pa(a, b);
}

void		case3b_102(t_stack *a, t_stack *b)
{
	if (dlst_size(b->head) == 3)
	{
		op_rrb(b);
		op_pa(a, b);
		op_pa(a, b);
		op_pa(a, b);
		return ;
	}
	op_pa(a, b);
	op_sb(b);
	op_pa(a, b);
	op_sa(a);
	op_pa(a, b);
}

void		case3b_201(t_stack *a, t_stack *b)
{
	op_pa(a, b);
	op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
}

void		case3b_120(t_stack *a, t_stack *b)
{
	op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
	op_pa(a, b);
}
