/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:24:59 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:28:37 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	dlst_queue_cut(t_dlst *head)
{
	t_dlst	*tail;

	if (head->prev != head->next)
		tail = head->prev;
	if (head->prev != NULL)
	{
		tail->next = NULL;
		head->prev = NULL;
	}
}

void	dlst_queue_link(t_dlst *head, t_dlst *tail)
{
	if (head->next == head->prev)
		return ;
	if (head != NULL && tail != NULL)
	{
		head->prev = tail;
		tail->next = head;
	}
}
