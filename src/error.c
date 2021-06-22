/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:36:45 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/22 10:02:48 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_arg(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Non numeric arguments found\n"
		COLOR_RESET, 2);
	exit(1);
}

void	error_dup(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Duplicate arguments found\n"
		COLOR_RESET, 2);
	exit(1);
}

void	error_overint(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Over the INT range arguments found.\n"
		COLOR_RESET, 2);
	exit(1);
}
