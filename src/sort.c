/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:07:13 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/03 19:49:58 by jisokang         ###   ########.fr       */
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
	swap_int(&(i->value), &(h->value));
	return i;
}

void	quick_sort(t_dlst *head, int left, int right)
{
	if (left < right)
	{
		q =
		quick_sort(head, left)
	}


}
