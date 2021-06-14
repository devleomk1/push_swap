/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:59:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/14 21:37:21 by jisokang         ###   ########.fr       */
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
		return ;
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

	tmp = *lst;
	// *lst의 node가 1개 일 때
	if ((*lst)->next == (*lst) && (*lst)->prev == (*lst))
		*lst = NULL;
	else
	{
		//head가 나가고 *lst->next랑 tail이랑 연결
		*lst = tmp->next;
		tmp->next = tmp;
		(*lst)->prev = tmp->prev;
		tmp->prev = tmp;
		(*lst)->prev->next = *lst;
	}
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
/**
 * lst 부터 n번째 다음있는 노드를 리턴한다.
 */
t_dlst	*dlst_count(t_dlst *lst, size_t n)
{
	t_dlst	*curr;

	if (lst == NULL || dlst_size(lst) < (int)n)
	{
		printf("count error\n");
		return (0);
	}
	curr = lst;
	while (n > 0)
	{
		// printf("n = %d\n", (int)n);
		curr = curr->next;
		n--;
	}
	return (curr);
}

// A utility function to find last node of linked list
t_dlst	*dlst_last(t_dlst *head)
{
	t_dlst	*tmp;
	tmp = head->prev;
	return (tmp);
}

void	dlst_queue_cut(t_dlst *head)
{
	t_dlst *tail;
	if (head->prev != head->next)
		tail = head->prev;
	if(head->prev != NULL)
	{
		tail->next = NULL;
		head->prev = NULL;
	}
}

void	dlst_queue_link(t_dlst *head, t_dlst *tail)
{
	// 이것도 이상하네
	if (head->next == head->prev)
		return ;
	if(head != NULL && tail != NULL)
	{
		head->prev = tail;
		tail->next = head;
	}
}

/* [BEFORE] -> [NEW] -> [AFTER] */
void	dlst_insert(t_dlst *before, t_dlst *new)
{
	printf("insert_START\n");
	//AFTER == before->next
	new->prev = before;
	new->next = before->next;
	before->next->prev = new;
	before->next = new;
	printf("insert_END\n");
}

void	dlst_print(t_dlst *head)
{
	t_dlst *curr;

	curr = head;
	while (curr->next != head)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("%d ", curr->value);
	printf("\n");
}

void	dlst_ndoe_swap_next(t_dlst **lst)
{
	int	tmp;

	if(lst == NULL || (*lst)->next == NULL || (*lst)->next == *lst)
		return ;
	tmp = (*lst)->value;
	(*lst)->value = (*lst)->next->value;
	(*lst)->next->value = tmp;
}

void	dlst_node_swap(t_dlst *lst1, t_dlst *lst2)
{
	t_dlst	*tmp_prev;
	t_dlst	*tmp_next;

	if(lst1 == NULL || lst2 == NULL || lst1 == lst2 )
		return ;
	if (lst1->next == lst2 || lst2->next == lst1)
		dlst_ndoe_swap_next(&lst1);
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

