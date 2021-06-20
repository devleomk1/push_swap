/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:31 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/20 01:24:16 by jisokang         ###   ########.fr       */
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
	t_dlst			*head;
}					t_stack;

typedef struct		s_count
{
	int				ra;
	int				pb;
	int				rb;
	int				pa;
}					t_count;

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
t_dlst	*copy_list(t_dlst *lst);
void	dlst_insert(t_dlst *before, t_dlst *new);
void	dlst_ndoe_swap_next(t_dlst **lst);
void	dlst_node_swap(t_dlst *lst1, t_dlst *lst2);
void	dlst_print(t_dlst *head);
void	node_swap(t_dlst *lst1, t_dlst *lst2);
void	dlst_clear(t_dlst *head);

/**
 * util_stack.c
 */
void	init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);
void	push_arg(t_stack *stack, int value);
void	push(t_stack *stack, t_dlst *new);
t_dlst	*pop_stack(t_stack *stack);
void	push_stack(t_stack *src, t_stack *dst);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	rev_rotate_stack(t_stack *stack);

/**
 * Utils
 * files : util.c, util_print.c
 */
int		ft_atoi(const char *str);
void	print_stack_lst(t_stack *stack);
void	print_2_stack(t_stack *stk1, t_stack *stk2);

/**
 * Operations
 * files : op_swap_and_push.c, op_rotate.c, op_rev_rotate.c
 */

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
int	op_pa(t_stack *a, t_stack *b);
int	op_pb(t_stack *a, t_stack *b);

int	op_ra(t_stack *a);
int	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);

void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

/**
 * Quick_sort
 * files: quick_sort.c
 */

void	quick_sort(t_dlst *head);

/**
 * Exit
 * files : exit.c
 */
void	error_exit(char *message);
void	error_arg(void);
void	error_dup(void);

/**
 * Check lst status
 * files : check_sort.c
 */
int		is_sort_lst(t_dlst *lst);
int		is_duplicate(t_dlst *lst);
void	print_sort_status(t_dlst *lst);
void	stack_status_check(t_stack *stk);

/**
 * Init push_swap
 * files : init.c
 */
void	push_swap(t_stack *a, t_stack *b, int argc, char **argv);

/**
 * Get median value
 * files : get_median.c
 */

int		get_mid_val(t_dlst *head, unsigned int len);

void	push_sort_AtoB(t_stack *a, t_stack *b, int range);
void	push_sort_BtoA(t_stack *a, t_stack *b, int range);

int		is_out_AtoB(t_stack *a, t_stack *b, int range);
int		is_out_BtoA(t_stack *a, t_stack *b, int range);

void	case3a_021(t_stack *a, t_stack *b);
void	case3a_201(t_stack *a, t_stack *b);
void	case3a_120(t_stack *a, t_stack *b);
void	case3a_210(t_stack *a, t_stack *b);

void	case3b_012(t_stack *a, t_stack *b);
void	case3b_021(t_stack *a, t_stack *b);
void	case3b_102(t_stack *a, t_stack *b);
void	case3b_201(t_stack *a, t_stack *b);
void	case3b_120(t_stack *a, t_stack *b);

void	print_check_rrb(t_stack *b, t_count cnt);
void	print_check_rra(t_stack *a, t_count cnt);

# endif
