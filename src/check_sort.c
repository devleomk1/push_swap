/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/08 19:26:38 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort_lst(t_dlst *lst)
{
	t_dlst	*curr;

	curr = lst;
	if (curr->next == curr && curr->prev == curr)
		return (TRUE);
	while (curr->next != lst)
	{
		if(curr->value > curr->next->value)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

int	is_duplicate(t_dlst *lst)
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
		curr = curr->next;
	}
	return (FALSE);
}

void	print_sort_status(t_dlst *lst)
{
	if (is_duplicate(lst) == TRUE)
		printf("Dupl\t: " STR_COLOR_RED "KO\n" STR_COLOR_RESET);
	else
		printf("Dupl\t: " STR_COLOR_GREEN "OK\n" STR_COLOR_RESET);

	if (is_sort_lst(lst) == TRUE)
		printf("Sort\t: " STR_COLOR_GREEN "OK\n" STR_COLOR_RESET);
	else
		printf("Sort\t: " STR_COLOR_RED "KO\n" STR_COLOR_RESET);
}
