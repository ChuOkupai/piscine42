SRCS		= ft_display_file.c \
			  ft_putstr_fd.c \
			  ft_strlen.c \
			  main.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_display_file

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
