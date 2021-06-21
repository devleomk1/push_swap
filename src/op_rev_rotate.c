/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:27 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 16:04:23 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/**
 * `rra`: Stack_a의 모든 원소들을 아래로 1 인덱스 만큼 내린다.
 *		  마지막 원소(Bot)는 첫 번째 원소(Top)가 된다.
 */
void	op_rra(t_stack *a)
{
	rev_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack *b)
{
	rev_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * `rrr`: 'rra'와 'rrb'를 동시에 수행한다.
 */
void	op_rrr(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
