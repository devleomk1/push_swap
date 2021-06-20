/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 22:04:47 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	sign;
	long	result;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error_arg();
		result = result * 10 + (str[i] - '0');
		if ((result > 2147483647 && sign == 1)
			|| (result > 2147483648 && sign == -1))
			error_overint();
		i++;
	}
	return (sign * result);
}

void	push_swap(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	if (argc <= 2)
		exit(0);
	init_stack(a);
	init_stack(b);
	i = 1;
	while (argc-- > 1)
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
