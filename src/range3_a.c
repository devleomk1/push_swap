/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range3_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:53:54 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:10:15 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * A : 0 2 1
 */
void	case3a_021(t_stack *a, t_stack *b)
{
	(void)b;
	op_ra(a);
	op_sa(a);
	op_rra(a);
}

/**
 * A : 2 0 1
 */
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

/**
 * A : 1 2 0
 */
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

/**
 * A : 2 1 0
 */
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
