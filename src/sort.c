/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:07:13 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/11 20:50:10 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		swap_int(int *a, int *b)
{
	int	tmp;
	if (*a == *b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_dlst	*partition(t_dlst *low, t_dlst *high)
{
	int		pivot;
	t_dlst	*i;
	t_dlst	*j;

	pivot = high->value;
	i = low->prev;
	j = low;
	while (j != high)
	{
		if (j->value <= pivot)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap_int(&(i->value), &(j->value));
		}
		j = j->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap_int(&(i->value), &(high->value));
	return i;
}
/**
 * _함수이름 : 코딩 규약 서브 함수
  */
static void	_quick_sort(t_dlst *low, t_dlst *high)
{
	t_dlst *p;

	if (high != NULL && low != high && low != high->next)
	{
		//printf("low :%d\n", low->value);
		//printf("high:%d\n", high->value);
		p = partition(low, high);
		_quick_sort(low, p->prev);
		_quick_sort(p->next, high);
	}
}


void	quick_sort(t_dlst *head)
{
	t_dlst	*tail;
	t_block	block;
	tail = head->prev;

	dlst_queue_cut(head);
	_quick_sort(head, tail);
	dlst_queue_link(head, tail);

	block.len = dlst_size(head);
	// block.min = head;
	block.mid = dlst_count(head, (block.len / 2));
	// block.max = tail;
	printf ("Len : %d\n", block.len);
	// printf ("min : %d\n", block.min->value);
	printf ("mid : %d\n", block.mid->value);
	// printf ("max : %d\n", block.max->value);
}
