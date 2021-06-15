/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/15 22:51:52 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap_AtoB(t_stack *a, t_stack *b, unsigned int range)
{
	int		ra_count;
	int		pb_count;
	int		tmp;
	t_block	block;

	ra_count = 0;
	pb_count = 0;
	if (range <= 1)
	{
		printf("IM OUT %d\n", range);
		return ;
	}
	else if (range == 2)
	{
		if (a->head->value > a->head->next->value)
			op_sa(a);
		return ;
	}
	else if (range == 3)
	{
		printf("IM OUT %d\n", range);
		return ;
	}
	get_lst_median_val(copy_list(a->head), &block);
	while (range > 0)
	{
		if (a->head->value > block.mid)
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
	tmp = ra_count;
	while (tmp > 0)
	{
		op_rra(a);
		tmp--;
	}
	printf("len : %d\n", block.len);
	printf("mid : %d\n", block.mid);
	printf("ra_cunt : %d\n", ra_count);
	print_2_stack(a, b);

	push_swap_AtoB(a, b, ra_count);
	push_swap_BtoA(a, b, pb_count);
	print_2_stack(a, b);
}

void	push_swap_BtoA(t_stack *a, t_stack *b, unsigned int range)
{
	int		rb_count;
	int		pa_count;
	int		tmp;
	t_block	block;

	printf("in BtoA\n");
	rb_count = 0;
	pa_count = 0;
	if (range <= 1)
	{
		op_pa(a, b);
		printf("IM OUT %d\n", range);
		return ;
	}
	else if (range == 2)
	{
		if (b->head->value > b->head->next->value)
			op_sb(b);
		op_pa(a, b);
		op_pa(a, b);
		return ;
	}
	else if (range <= 3)
	{
		printf("IM OUT %d\n", range);
		op_sb(b);
		op_pa(a, b);
		op_pa(a, b);
		op_pa(a, b);
		return ;
	}
	init_block(&block);
	get_lst_median_val(copy_list(b->head), &block);
	while (range > 0)
	{
		if (b->head->value > block.mid)
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
	tmp = rb_count;
	while (tmp > 0)
	{
		op_rrb(b);
		tmp--;
	}
	print_2_stack(a, b);
	push_swap_AtoB(a, b, pa_count);
	push_swap_BtoA(a, b, rb_count);
	//print_2_stack(a, b);
}


int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	//t_block	block;

	init_push_swap(&a, &b, argc, argv);
	print_2_stack(&a, &b);

	//get_lst_median_val(a.head, &block);
	push_swap_AtoB(&a, &b, dlst_size(a.head));

	// push()함수 잘못 됨!
	// main()함수 입력 받을 때만 dlst_add_back으로 받고,
	// 나머지 연산들은 dlst_add_front여야 하는거 아님?
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
