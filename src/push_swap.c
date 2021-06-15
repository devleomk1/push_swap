/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/16 00:43:26 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	out_range3_a(t_stack *a, t_stack *b, int range);
int	out_range3_b(t_stack *a, t_stack *b, int range);

void	push_swap_AtoB(t_stack *a, t_stack *b, unsigned int range)
{
	int		ra_count;
	int		pb_count;
	int		tmp;
	t_block	block;

	ra_count = 0;
	pb_count = 0;
	if(out_range3_a(a, b, range) == TRUE)
		return ;
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
	//printf("----------AtoB-----------\n");
	//printf("len : %d\n", block.len);
	//printf("mid : %d\n", block.mid);
	//printf("ra_cunt : %d\n", ra_count);
	//print_2_stack(a, b);

	push_swap_AtoB(a, b, ra_count);
	push_swap_BtoA(a, b, pb_count);
	//print_2_stack(a, b);
}

void	push_swap_BtoA(t_stack *a, t_stack *b, unsigned int range)
{
	int		rb_count;
	int		pa_count;
	int		tmp;
	t_block	block;

	rb_count = 0;
	pa_count = 0;
	if(out_range3_b(a, b, range) == TRUE)
		return ;
	init_block(&block);
	get_lst_median_val(copy_list(b->head), &block);
	while (range > 0)
	{
		if (b->head->value > block.mid)
		{
			//op_rb(b);
			op_pa(a, b);
			pa_count++;
		}
		else
		{
			op_rb(b);
			//op_pa(a, b);
			rb_count++;
		}
		range--;
	}
	tmp = rb_count;
	while (tmp > 0)
	{
		op_rrb(b);
		tmp--;
	}
	//printf("----------BtoA-----------\n");
	//printf("len : %d\n", block.len);
	//printf("mid : %d\n", block.mid);
	//printf("rb_cunt : %d\n", rb_count);
	//print_2_stack(a, b);
	push_swap_AtoB(a, b, pa_count);
	push_swap_BtoA(a, b, rb_count);
	//print_2_stack(a, b);
}

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
	{
		op_pa(a, b);
		return (1);
	}
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	//t_block	block;

	init_push_swap(&a, &b, argc, argv);
	//print_2_stack(&a, &b);

	//get_lst_median_val(a.head, &block);
	push_swap_AtoB(&a, &b, dlst_size(a.head));

	// push()함수 잘못 됨!
	// main()함수 입력 받을 때만 dlst_add_back으로 받고,
	// 나머지 연산들은 dlst_add_front여야 하는거 아님?
	//print_2_stack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
