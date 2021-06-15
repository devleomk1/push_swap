/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:25:23 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/16 00:44:58 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_push_swap(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		error_exit("Argument Error");
	else if(argc == 2)
		exit(0);
	init_stack(a);
	init_stack(b);
	i = 1;
	while (argv[i] != NULL)
		push_arg(a, ft_atoi(argv[i++]));
	stack_status_check(a);
	//printf(COLOR_GREEN "init OK\n" COLOR_RESET);
}

void	init_block(t_block *block)
{
	block->len = 0;
	block->mid = 0;
}
