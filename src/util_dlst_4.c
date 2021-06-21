/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_dlst_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:55:26 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 19:57:15 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlst	*dlst_new_copy(t_dlst *lst)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
		return (NULL);
	new->value = lst->value;
	return (new);
}

t_dlst	*dlst_copy_lst(t_dlst *lst)
{
	t_dlst	*curr;
	t_dlst	*tmp;
	t_dlst	*tmp2;

	curr = lst;
	tmp2 = lst;
	while (curr->next != tmp2)
	{
		tmp = dlst_new_copy(curr);
		dlst_add_back(&lst, tmp);
		curr = curr->next;
	}
	return (tmp);
}

t_dlst	*copy_list(t_dlst *lst)
{
	t_dlst	*curr;
	t_dlst	*cpy;

	cpy = NULL;
	curr = lst;
	while (curr->next != lst)
	{
		dlst_add_back(&cpy, dlst_new(curr->value));
		curr = curr->next;
	}
	dlst_add_back(&cpy, dlst_new(curr->value));
	return (cpy);
}
