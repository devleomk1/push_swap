# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 17:24:47 by jisokang          #+#    #+#              #
#    Updated: 2021/05/30 18:21:19 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

SRCS	=	push_swap.c \
			util_double_list.c \
			util_stack.c \
			util.c \
			op_swap_and_push.c \
			op_rotate.c

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	$(AR) $@ $?

bonus :

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
