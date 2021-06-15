/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:47:47 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/15 21:58:07 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_block	*get_lst_median_val(t_dlst *head, t_block *block)
{
	//printf("in get_lst_median_val\n");
	quick_sort(head);
	block->len = dlst_size(head);
	block->mid = (dlst_count(head, (block->len / 2)))->value;
	dlst_clear(head);

	//printf("LEN : %d\n", block->len);
	//printf("MID : %d\n", block->mid);
	//printf("GET mid Val" COLOR_GREEN " OK\n" COLOR_RESET);
	return (block);
}
