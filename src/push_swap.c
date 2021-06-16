/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/17 04:24:15 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		error_arg();
	else if (argc == 2)
		exit(0);
	init_stack(a);
	init_stack(b);
	i = 1;
	while (argv[i] != NULL)
		push_arg(a, ft_atoi(argv[i++]));
	stack_status_check(a);
	push_sort_AtoB(a, b, dlst_size(a->head));
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	push_swap(&a, &b, argc, argv);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
