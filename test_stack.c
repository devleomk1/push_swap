/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:31:59 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/03 19:33:19 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{

	// '*' : ~가 가르킨 값
	// '&' : ~의 주소
	// **lst
	//  *lst
	if (lst == NULL || new == NULL)	//lst의 Top Node가 NULL || new Node가 NULL 이면
		return ;					//함수 종료
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		new->next = NULL;
	new->prev = NULL;
	*lst = new;
}

t_list	*ft_lstpop(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void	*ft_swap_a2(t_list **stack_a)
{
	t_list *tmp;

	if(stack_a == NULL)
		return (NULL);
	if ((*stack_a)->next == NULL)
		return (NULL);
	tmp = (*stack_a)->content;
	//printf("s_a->con : %s\n", (*stack_a)->content);
	//printf("s_a->nex->con : %s\n", (*stack_a)->next->content);
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*curr;
	t_list	*pop;
	t_list	*stack_a;

	if(argc < 2)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_front(&stack_a, ft_lstnew(argv[i]));
		i++;
	}
	curr = stack_a;
	printf("Stack A\n");
	while (curr != NULL)
	{
		printf("|%3s|\n", curr->content);
		curr = curr->next;
	}
	printf("|---|\n\n");
	curr = stack_a;
	ft_swap_a(&stack_a);
	while (curr != NULL)
	{
		printf("|%3s|\n", curr->content);
		curr = curr->next;
	}
	printf("|---|\n\n");
	//curr = stack_a;
	//pop = ft_lstpop(&curr);
	//printf("POP! : %s\n\n", pop->content);
	//while (curr != NULL)
	//{
	//	printf("|%3s|\n", curr->content);
	//	curr = curr->next;
	//}
	//printf("|---|\n\n");
	return (0);
}
