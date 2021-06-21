/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:13:01 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/21 17:50:10 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//void	ft_putstr_fd(char *s, int fd)
//{
//	size_t	i;

//	if (s == NULL)
//		return ;
//	i = 0;
//	while (s[i] != '\0')
//	{
//		write(fd, &s[i], 1);
//		i++;
//	}
//}

//static int	ft_isdigit(int c)
//{
//	if (c >= '0' && c <= '9')
//		return (1);
//	else
//		return (0);
//}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi_pushswap(const char *str)
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
