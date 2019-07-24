SRCS		= ex00/btree_create_node.c \
			  ex01/btree_apply_prefix.c \
			  ex02/btree_apply_infix.c \
			  ex03/btree_apply_suffix.c \
			  ex04/btree_insert_data.c \
			  ex05/btree_search_item.c \
			  ex06/btree_level_count.c \
			  ex07/btree_apply_by_level.c \
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
