/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:31 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/28 15:05:48 by jisokang         ###   ########.fr       */
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
	t_dlst	*tail;
}					t_stack;

t_dlst	*ft_dlst_new(int value);
void	ft_dlst_add_front(t_dlst **lst, t_dlst *new);
void	ft_dlst_add_back(t_dlst **lst, t_dlst *new);
t_dlst	*ft_dlst_pop(t_dlst **lst);
int		ft_dlst_size(t_dlst *lst);
void	ft_dlst_insert(t_dlst *before, t_dlst *new);

# endif
