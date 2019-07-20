SRCS		= ex00/ft_create_elem.c \
			  ex01/ft_list_push_front.c \
			  ex02/ft_list_size.c \
			  ex03/ft_list_last.c \
			  ex04/ft_list_push_back.c \
			  ex05/ft_list_push_strs.c \
			  ex06/ft_list_clear.c \
			  ex07/ft_list_at.c \
			  ex08/ft_list_reverse.c \
			  ex09/ft_list_foreach.c \
			  ex10/ft_list_foreach_if.c \
			  ex11/ft_list_find.c \
			  ex12/ft_list_remove_if.c \
			  ex13/ft_list_merge.c \
			  ex14/ft_list_sort.c \
			  ex15/ft_list_reverse_fun.c \
			  ex16/ft_sorted_list_insert.c \
			  ex17/ft_sorted_list_merge.c \
			  main.c

OBJS		= ${SRCS:.c=.o}

NAME		= a.out

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

.c.o:
			gcc ${CFLAGS} -I. -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
