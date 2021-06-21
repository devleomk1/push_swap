# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 17:24:47 by jisokang          #+#    #+#              #
#    Updated: 2021/06/21 17:56:31 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

LIB_DIR		=	./lib/
LIB_NAME	=	lib_jisokang.a

SRC		=	push_swap.c \
			util_double_list.c \
			util_stack.c \
			util.c \
			util_print.c \
			op_swap_and_push.c \
			op_rotate.c \
			op_rev_rotate.c \
			quick_sort.c \
			error.c \
			check_lst.c \
			get_mid_val.c \
			range3_a.c \
			range3_b.c \
			push_sort.c \
			push_sort_out.c

SRCS	= $(addprefix $(SRCS_DIR), $(OBJS))
LIBS	= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS	= $(SRC:.c=.o)

#	make -C $(LIB_DIR)
#	$(CC) $(CFLAGS) -c $< -I $(INCS_DIR)
# gcc option
# -c 		: 오브젝트 파일 생성
# -I <dir>	: 참조할 헤더파일의 주소를 추가
# -o		: 실행파일을 만든다.


all : $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

#$(NAME) :
#	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR)

$(NAME) : $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(SRCS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
