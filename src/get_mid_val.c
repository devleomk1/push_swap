/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:47:47 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 17:59:24 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_mid_val(t_dlst *head, unsigned int range)
{
	int	value;

	quick_sort(head);
	value = (dlst_count(head, (range / 2) - 1))->value;
	dlst_clear(head);
	return (value);
}
