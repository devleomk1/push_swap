/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:31 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/08 20:22:17 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "printf_color.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_dlst
{
	int				value;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}					t_dlst;

typedef struct		s_stack
{
	t_dlst	*head;
}					t_stack;


/**
 * util_double_list.c
 */
t_dlst	*dlst_new(int value);
void	dlst_add_front(t_dlst **lst, t_dlst *new);
void	dlst_add_back(t_dlst **lst, t_dlst *new);
t_dlst	*dlst_pop(t_dlst **lst);
int		dlst_size(t_dlst *lst);
t_dlst	*dlst_count(t_dlst *lst, size_t n);
t_dlst	*dlst_last(t_dlst *lst);
void	dlst_queue_cut(t_dlst *head);
void	dlst_queue_link(t_dlst *head, t_dlst *tail);
void	dlst_insert(t_dlst *before, t_dlst *new);
void	dlst_ndoe_swap_next(t_dlst **lst);
void	dlst_node_swap(t_dlst *lst1, t_dlst *lst2);
void	node_swap(t_dlst *lst1, t_dlst *lst2);

/**
 * util_stack.c
 */
void	init_stack(t_stack *stack);
void	push_new(t_stack *stack, int value);
void	push(t_stack *stack, t_dlst *new);
t_dlst	*pop_stack(t_stack *stack);
void	push_stack(t_stack *src, t_stack *dst);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);

/**
 * Utils
 * files : util.c
 */
int		ft_atoi(const char *str);

/**
 * Operations
 * files : op_swap_and_push.c, op_rotate.c, op_rev_rotate.c
 */
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);

void	op_ra(t_stack *a);
void	op_rb(t_stack *b);

/**
 * sort.c
 */
void	quick_sort(t_dlst *head);

/**
 * Exit
 * files : exit.c
 */
void	error_exit(char *message);

/**
 * Check lst status
 * files : check_sort.c
 */
int		is_sort_lst(t_dlst *lst);
int		is_duplicate(t_dlst *lst);
void	print_sort_status(t_dlst *lst);

# endif
