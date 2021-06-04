/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:07:13 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/04 14:41:52 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_dlst	*partition(t_dlst *low,	t_dlst *high)
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

void	_quick_sort(t_dlst *low, t_dlst *high)
{
	t_dlst *p;

	if (high != NULL && low != high && low != high->next)
	{
		p = partition(low, high);
		_quick_sort(low, p->prev);
		_quick_sort(p->next, high);
	}

}

void	quick_sort(t_dlst *head)
{
	t_dlst	*tail = head->prev;
	_quick_sort(head, tail);
}
