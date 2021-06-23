/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:13:01 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/23 14:16:50 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi_pushswap(const char *str)
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
	if (!ft_isdigit(str[i]))
		error_arg();
	return (sign * result);
}

t_dlst	*lst_count(t_dlst *lst, size_t n)
{
	t_dlst	*curr;

	if (lst == NULL)
		return (0);
	curr = lst;
	while (n > 0)
	{
		curr = curr->next;
		n--;
	}
	return (curr);
}

void	print_lst_nul(t_dlst *head)
{
	t_dlst	*curr;

	curr = head;
	while (curr->next != NULL)
	{
		ft_printf("%d ", curr->value);
		curr = curr->next;
	}
	ft_printf("%d ", curr->value);
	ft_printf("\n");
}
