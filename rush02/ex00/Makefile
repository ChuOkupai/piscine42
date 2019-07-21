SRCS		= ft/ft_atol.c \
			  ft/ft_check_args.c \
			  ft/ft_file_load.c \
			  ft/ft_isdigit.c \
			  ft/ft_isprint.c \
			  ft/ft_is_valid.c \
			  ft/ft_isspace.c \
			  ft/ft_putchar.c \
			  ft/ft_putstr.c \
			  ft/ft_strlen.c \
			  ft/ft_strncpy.c \
			  ft_dict/ft_dict_cmp.c \
			  ft_dict/ft_dict_clear.c \
			  ft_dict/ft_dict_create.c \
			  ft_dict/ft_dict_create_elem.c \
			  ft_dict/ft_dict_in.c \
			  ft_dict/ft_print.c \
			  ft_list/ft_create_elem.c \
			  ft_list/ft_list_clear.c \
			  ft_list/ft_list_find.c \
			  ft_list/ft_sorted_list_insert.c \
			  main.c

OBJS		= $(addprefix srcs/, ${SRCS:.c=.o})

NAME		= rush-02

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

.c.o:
			gcc ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
