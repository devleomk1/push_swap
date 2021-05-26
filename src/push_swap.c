/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/26 00:23:19 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	push_swap(void)
{

}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	t_dlst	*curr;
	t_dlst	*circular;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		//ft_dlst_add_front(&circular, ft_dlst_new(argv[i]));
		ft_dlst_add_back(&circular, ft_dlst_new(argv[i]));
		i++;
	}
	len = ft_dlst_size(circular);
	printf("List len = %d\n\n", len);
	curr = circular;
	i = 0;
	while (i < 10)
	{
		printf("|%s|->", curr->content);
		curr = curr->next;
		i++;
	}


	return (0);
}
