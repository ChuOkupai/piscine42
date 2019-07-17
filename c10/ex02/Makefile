SRCS		= ft_atoi.c \
			  ft_putchar_fd.c \
			  ft_puterr.c \
			  ft_putstr_fd.c \
			  ft_strcmp.c \
			  ft_strlen.c \
			  ft_strncpy.c \
			  ft_tail.c \
			  main.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_tail

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
