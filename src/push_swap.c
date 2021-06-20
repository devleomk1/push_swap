/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 15:58:42 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		skip_atoi(const char **s)
{
	int	i;

	i = 0;
	while (ft_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return (i);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	parse_arg(t_stack *stack, int argc, char **argv)
{
	int	i;

	if (argc <= 2)
		exit(0);
	i = 1;
	while (argc-- > 1)
	{
		if (ft_isdigit(*argv[i]))
			push_arg(stack, ft_atoi(argv[i++]));
		else
			error_arg();
	}
}

void	push_swap(t_stack *a, t_stack *b, int argc, char **argv)
{
	// arg가 없으면 없는걸로 끝나야지.error_arg();
	init_stack(a);
	init_stack(b);
	parse_arg(a, argc, argv);
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
