/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:59:09 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/26 17:28:46 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*ft_dlst_new(void *content)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->prev = new;
	new->next = new;
	return (new);
}
/*
new 노드가 자기 자신을 가리켜야 예외처리 하기가 쉽다.
*/

void	ft_dlst_add_front(t_dlst **lst, t_dlst *new)
{
	if (lst == NULL || new == NULL)	//lst의 Top Node가 NULL || new Node가 NULL 이면
		return ;					//함수 종료
	if (*lst)
	{
		new->prev = (*lst)->prev;	//서순 조심
		(*lst)->prev->next = new;
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}

void	ft_dlst_add_back(t_dlst **lst, t_dlst *new)
{
	if (lst == NULL || new == NULL)	//lst의 Top Node가 NULL || new Node가 NULL 이면
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

t_dlst	*ft_dlst_pop(t_dlst **lst)
{
	t_dlst *tmp;

	if (lst == NULL)
		return ;
	//head가 나가고 *lst->next랑 tail이랑 연결
	//lst->next = lst;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = tmp;
	(*lst)->prev = tmp->prev;
	tmp->prev = tmp;
	(*lst)->prev->next = *lst;

	return (tmp);
}

int	ft_dlst_size(t_dlst *lst)
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
void	ft_dlst_insert(t_dlst *before, t_dlst *new)
{
	//AFTER == before->next
	new->prev = before;
	new->next = before->next;
	before->next->prev = new;
	before->next = new;
}
