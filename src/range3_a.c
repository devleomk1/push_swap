/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range3_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:53:54 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 10:04:08 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	case3a_021(t_stack *a, t_stack *b)
{
	(void)b;
	op_ra(a);
	op_sa(a);
	op_rra(a);
}

void	case3a_201(t_stack *a, t_stack *b)
{
	(void)b;
	if (dlst_size(a->head) == 3)
		op_ra(a);
	else
	{
		op_sa(a);
		op_ra(a);
		op_sa(a);
		op_rra(a);
	}
}

void	case3a_120(t_stack *a, t_stack *b)
{
	if (dlst_size(a->head) == 3)
		op_rra(a);
	else
	{
		op_ra(a);
		op_ra(a);
		op_pb(a, b);
		op_rra(a);
		op_rra(a);
		op_pa(a, b);
	}
}

void	case3a_210(t_stack *a, t_stack *b)
{
	(void)b;
	if (dlst_size(a->head) == 3)
	{
		op_sa(a);
		op_rra(a);
	}
	else
	{
		op_sa(a);
		op_ra(a);
		op_sa(a);
		op_rra(a);
		op_sa(a);
	}
}
