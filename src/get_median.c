/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:47:47 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/14 18:07:15 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*get_lst_median_val(t_dlst *head, t_block *block)
{
	quick_sort(head);
	block->len = dlst_size(head);
	block->mid = dlst_count(head, (block->len / 2))->value;
	// block->mid = block->len / 2;
	printf("LEN : %d\n", block->len);
	printf("MID : %d\n", block->mid);
	return (block);
}
