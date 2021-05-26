/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:28:31 by jisokang          #+#    #+#             */
/*   Updated: 2021/05/26 19:48:39 by jisokang         ###   ########.fr       */
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
	void			*content;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}					t_dlst;

t_dlst	*ft_dlst_new(void *content);
void	ft_dlst_add_front(t_dlst **lst, t_dlst *new);
void	ft_dlst_add_back(t_dlst **lst, t_dlst *new);
t_dlst	*ft_dlst_pop(t_dlst **lst);
int		ft_dlst_size(t_dlst *lst);
void	ft_dlst_insert(t_dlst *before, t_dlst *new);

# endif
