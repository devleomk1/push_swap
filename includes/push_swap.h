/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:31 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/29 21:11:07 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_dlst
{
	int				value;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}					t_dlst;

typedef struct		s_stack
{
	t_dlst	*head;
	// t_dlst	*tail;
}					t_stack;

/**
 * util_double_list.c
 */
t_dlst	*dlst_new(int value);
void	dlst_add_front(t_dlst **lst, t_dlst *new);
void	dlst_add_back(t_dlst **lst, t_dlst *new);
t_dlst	*dlst_pop(t_dlst **lst);
int		dlst_size(t_dlst *lst);
void	dlst_insert(t_dlst *before, t_dlst *new);
/**
 * util_stack.c
 */
void	init_stack(t_stack *stack);
void	push_new(t_stack *stack, int value);
void	push(t_stack *stack, t_dlst *new);
t_dlst	*pop_stack(t_stack *stack);
void	push_stack(t_stack *src, t_stack *dst);
void	swap_stack(t_stack *stack);

/**
 * util.c
 */
int		ft_atoi(const char *str);

# endif
