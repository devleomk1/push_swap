/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:36:45 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 17:16:01 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Check non numeric parameter
 * ex: "3 2 one 0"
 * fd = 2 is stderr
 */
void	error_arg(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Non numeric arguments found\n"
		COLOR_RESET, 2);
	exit(1);
}

/**
 * Check duplicate numeric parameter
 * ex : " 3 2 1 1"
 * fd = 2 is stderr
 */
void	error_dup(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Duplicate arguments found\n"
		COLOR_RESET, 2);
	exit(1);
}

/**
 * Check MAXINT
 * ex : "2147483648 1 2 3"
 */
void	error_overint(void)
{
	ft_putstr_fd(COLOR_RED
		"Error : Over the INT range arguments found.\n"
		COLOR_RESET, 2);
	exit(1);
}
