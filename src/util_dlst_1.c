/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:13:24 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:28:02 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Function to find the length of
 * a circularly linked list.
 */
int	dlst_size(t_dlst *lst)
{
	int		i;
	t_dlst	*curr;

	if (lst == NULL)
		return (0);
	i = 1;
	curr = lst;
	while (curr->next != lst)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

/**
 * Return the 'n'th node from the head of lst.
 */
t_dlst	*dlst_count(t_dlst *lst, size_t n)
{
	t_dlst	*curr;

	if (lst == NULL || dlst_size(lst) < (int)n)
		return (0);
	curr = lst;
	while (n > 0)
	{
		curr = curr->next;
		n--;
	}
	return (curr);
}

/**
 * Function to find last node of linked list
 */
t_dlst	*dlst_last(t_dlst *head)
{
	t_dlst	*tmp;

	tmp = head->prev;
	return (tmp);
}

t_dlst	*dlst_pop(t_dlst **lst)
{
	t_dlst	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = *lst;
	if ((*lst)->next == (*lst) && (*lst)->prev == (*lst))
		*lst = NULL;
	else
	{
		*lst = tmp->next;
		tmp->next = tmp;
		(*lst)->prev = tmp->prev;
		tmp->prev = tmp;
		(*lst)->prev->next = *lst;
	}
	return (tmp);
}
