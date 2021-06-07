/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/07 21:31:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort_lst(t_dlst *lst)
{
	t_dlst	*curr;

	curr = lst;
	if (curr->next == curr && curr->prev == curr)
		return (TRUE);
	while (curr->next != lst);
	{
		if(curr->value < curr->next->value)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

