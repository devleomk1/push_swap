/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:07:13 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 18:00:24 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_int(int *a, int *b)
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
	return (i);
}

/**
 * _function_name() : it's mean sub function.
 */
static void	_quick_sort(t_dlst *low, t_dlst *high)
{
	t_dlst	*p;
	if (high != NULL && low != high && low != high->next)
	{

		p = partition(low, high);
		_quick_sort(low, p->prev);
		_quick_sort(p->next, high);
	}
}

/**
 * Quick sort for Doubly linked list
 * When a circular list comes in,
 * head and tail are cut and reattached after sorting.
 */
void	quick_sort(t_dlst *head)
{
	t_dlst	*tail;

	tail = head->prev;
	dlst_queue_cut(head);
	_quick_sort(head, tail);
	dlst_queue_link(head, tail);
}

t_dlst	*lst_count(t_dlst *lst, size_t n)
{
	t_dlst	*curr;

	if (lst == NULL)
		return (0);
	curr = lst;
	while (n > 0)
	{
		curr = curr->next;
		n--;
	}
	return (curr);
}

void	print_lst_nul(t_dlst *head)
{
	t_dlst *curr;

	curr = head;
	while (curr->next != NULL)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("%d ", curr->value);
	ft_printf("\n");
}
