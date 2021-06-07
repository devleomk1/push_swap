# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 17:24:47 by jisokang          #+#    #+#              #
#    Updated: 2021/06/07 21:10:13 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

SRC		=	push_swap.c \
			util_double_list.c \
			util_stack.c \
			util.c \
			op_swap_and_push.c \
			op_rotate.c \
			sort.c \
			exit.c

SRCS	= $(addprefix $(SRCS_DIR),$(SRC))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?
#	$(CC) $(CFLAGS) -c $< -I $(INCS_DIR)
# gcc option
# -c 		: 오브젝트 파일 생성
# -I <dir>	: 참조할 헤더파일의 주소를 추가
# -o		: 실행파일을 만든다.

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR)

bonus :

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
