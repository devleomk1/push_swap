/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:33:02 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:46:16 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * *lst head 앞에 새 노드 *new를 추가하고
 * head를 *new로 변경하는 함수
 */
void	dlst_add_front(t_dlst **lst, t_dlst *new)
{
	if (new == NULL)
		return ;
	if (*lst)
	{
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}

/**
 * *lst tail 뒤에 새 노드 *new를 추가하는 함수
 * *lst가 없으면 *new를 lst의 head로 준다.
 */
void	dlst_add_back(t_dlst **lst, t_dlst *new)
{
	if (new == NULL)
		return ;
	if (*lst)
	{
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		*lst = new;
}

void	dlst_node_swap_next(t_dlst **lst)
{
	if (lst == NULL || (*lst)->next == NULL || (*lst)->next == *lst)
		return ;
	ft_swap_int(&(*lst)->value, &(*lst)->next->value);
}

void	dlst_node_swap(t_dlst *lst1, t_dlst *lst2)
{
	t_dlst	*tmp_prev;
	t_dlst	*tmp_next;

	if (lst1 == NULL || lst2 == NULL || lst1 == lst2)
		return ;
	if (lst1->next == lst2 || lst2->next == lst1)
		dlst_node_swap_next(&lst1);
	else
	{
		tmp_prev = lst2->prev;
		tmp_next = lst2->next;
		lst2->prev = lst1->prev;
		lst2->next = lst1->next;
		lst1->prev = tmp_prev;
		lst1->next = tmp_next;
		if (lst2->next != NULL)
			lst2->next->prev = lst2;
		if (lst2->prev != NULL)
			lst2->prev->next = lst2;
		if (lst1->next != NULL)
			lst1->next->prev = lst1;
		if (lst1->prev != NULL)
			lst1->prev->next = lst1;
	}
}
