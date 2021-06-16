/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:47:47 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 02:06:03 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_mid_val(t_dlst *head, unsigned int len)
{
	int	value;

	quick_sort(head);
	value = (dlst_count(head, (len / 2)-1))->value;
	dlst_clear(head);
	return (value);
}
