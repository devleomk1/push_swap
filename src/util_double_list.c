/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:59:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/29 20:46:39 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		printf("MALLOC_ERROR\n");
		return (NULL);
	}
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

/**
 * *lst head 앞에 새 노드 *new를 추가하고
 * head를 *new로 변경하는 함수
 */
void	dlst_add_front(t_dlst **lst, t_dlst *new)
{
	if (new == NULL)
	{
		printf("NULL_ERROR_dlst_add_front\n");
		return ;
	}
	if (*lst)
	{
		new->prev = (*lst)->prev;	//서순 조심
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
		new->prev = (*lst)->prev;	//서순 조심
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		*lst = new;

}

t_dlst	*dlst_pop(t_dlst **lst)
{
	t_dlst *tmp;

	if (lst == NULL)
		return (NULL);
	//head가 나가고 *lst->next랑 tail이랑 연결
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = tmp;
	(*lst)->prev = tmp->prev;
	tmp->prev = tmp;
	(*lst)->prev->next = *lst;

	return (tmp);
}

/**
 * 원형 연결 리스트의 길이를 구하는 함수.
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

/* [BEFORE] -> [NEW] -> [AFTER] */
void	dlst_insert(t_dlst *before, t_dlst *new)
{
	//AFTER == before->next
	new->prev = before;
	new->next = before->next;
	before->next->prev = new;
	before->next = new;
}
