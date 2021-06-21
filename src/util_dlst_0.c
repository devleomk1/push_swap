/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:59:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * int value를 데이터로 갖는
 * 새로운 Double 연결 리스트 노드 생성
 * new 노드가 자기 자신을 가리켜야 예외처리 하기가 쉽다.
 */
t_dlst	*dlst_new(int value)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
	{
		ft_putstr_fd("Malloc error\n", 2);
		return (NULL);
	}
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

/**
 * BEFORE -> "NEW" -> AFTER
 */
void	dlst_insert(t_dlst *before, t_dlst *new)
{
	new->prev = before;
	new->next = before->next;
	before->next->prev = new;
	before->next = new;
}

void	dlst_clear(t_dlst *head)
{
	t_dlst	*curr;
	t_dlst	*next;

	curr = head;
	if (!curr)
		return ;
	while (1)
	{
		next = curr->next;
		free(curr);
		curr = next;
		if (curr == head)
			return ;
	}
}
