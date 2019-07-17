/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:51:18 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 23:47:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

char	*ft_load_file(int fd, unsigned int *size)
{
	char	buf[2048];
	char	*content;
	char	*tmp;
	int		len;

	if (!(content = malloc(sizeof(char))))
		return (NULL);
	*content = '\0';
	*size = 0;
	while ((len = read(fd, buf, 2048)) > 0)
	{
		if (!(tmp = malloc((*size + len) * sizeof(char))))
			break ;
		tmp = ft_strncpy(tmp, content, *size);
		free(content);
		ft_strncpy(tmp + *size, buf, len);
		content = tmp;
		*size += len;
		content[*size] = '\0';
	}
	if (len)
		free(content);
	return ((len) ? NULL : content);
}

int		ft_tail(char *path, unsigned int n, int count, int print_path)
{
	char			*content;
	int				fd;
	unsigned int	size;

	fd = (path) ? open(path, O_RDONLY) : STDIN_FILENO;
	if (fd < 0)
		return (-1);
	content = ft_load_file(fd, &size);
	if (fd != STDIN_FILENO)
		close(fd);
	if (!content)
		return (-1);
	if (print_path)
	{
		if (count)
			ft_putchar_fd('\n', 1);
		ft_putstr_fd("==> ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(" <==\n", 1);
	}
	if (n > size)
		n = size;
	ft_putstr_fd(content + size - n, 1);
	free(content);
	return (0);
}
