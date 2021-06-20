/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:36:45 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 00:15:28 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(char *message)
{
	printf(COLOR_RED "%s" COLOR_RESET "\n", message);
	exit(0);
}

/**
 * Check non numeric parameter
 * ex: "3 2 one 0"
 */
void	error_arg(void)
{
	write(2, COLOR_RED"Error : Non numeric arguments found\n"COLOR_RESET, 46);
	exit(0);
}

/**
 * Check duplicate numeric parameter
 * ex : " 3 2 1 1"
 */
void	error_dup(void)
{
	write(2, COLOR_RED"Error : Duplicate arguments found\n"COLOR_RESET, 44);
	exit(0);
}

/**
 * Check MAXINT
 * ex : "2147483648 1 2 3"
 */
void	error_overint(void)
{
	write(2, COLOR_RED"Error : Over the INT range arguments found.\n"COLOR_RESET, 54);
}
