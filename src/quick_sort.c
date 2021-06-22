/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:07:13 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 10:13:30 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			ft_swap_int(&(i->value), &(j->value));
		}
		j = j->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	ft_swap_int(&(i->value), &(high->value));
	return (i);
}

static void		sub_quick_sort(t_dlst *low, t_dlst *high)
{
	t_dlst	*p;

	if (high != NULL && low != high && low != high->next)
	{
		p = partition(low, high);
		sub_quick_sort(low, p->prev);
		sub_quick_sort(p->next, high);
	}
}

void			quick_sort(t_dlst *head)
{
	t_dlst	*tail;

	tail = dlst_last(head);
	dlst_queue_cut(head);
	sub_quick_sort(head, tail);
	dlst_queue_link(head, tail);
}

int				get_mid_val(t_dlst *head, unsigned int range)
{
	int	value;

	quick_sort(head);
	value = (dlst_count(head, (range / 2) - 1))->value;
	dlst_clear(head);
	return (value);
}
