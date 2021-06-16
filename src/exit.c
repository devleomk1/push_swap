/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:36:45 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 04:05:10 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(char *message)
{
	printf(COLOR_RED "%s" COLOR_RESET "\n", message);
	exit(0);
}

void	error_duplicate(void)
{
	write(2, COLOR_RED"Error : Duplicate node found\n"COLOR_RESET, 39);
	exit(0);
}
