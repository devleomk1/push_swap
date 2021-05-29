/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:08:26 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/26 21:11:21 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*push(t_dlst *src, t_dlst *dst)
{
	t_dlst	*tmp;
	if (src == NULL)
		return ;
	tmp = ft_dlst_pop(src);
	ft_dlst_add_front(dst, tmp);
}

