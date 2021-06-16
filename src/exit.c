/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:36:45 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 04:13:22 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(char *message)
{
	printf(COLOR_RED "%s" COLOR_RESET "\n", message);
	exit(0);
}

void	error_arg(void)
{
	write(2, COLOR_RED"Wrong Arguments found\n"COLOR_RESET, 32);
	exit(0);
}

void	error_dup(void)
{
	write(2, COLOR_RED"Duplicate node found\n"COLOR_RESET, 31);
	exit(0);
}
