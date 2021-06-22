/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 10:07:07 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sort_lst(t_dlst *lst)
{
	t_dlst	*curr;

	curr = lst;
	if (curr->next == curr && curr->prev == curr)
		return (TRUE);
	while (curr->next != lst)
	{
		if (curr->value > curr->next->value)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

static int	is_duplicate(t_dlst *lst)
{
	t_dlst	*tmp;
	t_dlst	*curr;

	if (lst->next == lst && lst->prev == lst)
		return (FALSE);
	curr = lst;
	while (curr->next != lst)
	{
		tmp = curr->next;
		while (tmp->next != curr)
		{
			if (curr->value == tmp->value)
				return (TRUE);
			tmp = tmp->next;
		}
		if (curr->value == tmp->value)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

void		check_stack(t_stack *stk)
{
	if (is_duplicate(stk->head) == TRUE)
		error_dup();
	if (is_sort_lst(stk->head) == TRUE)
		exit(0);
}
