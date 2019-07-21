/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:51:18 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/20 23:15:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

char	*ft_file_read(int fd)
{
	char	buf[2048];
	char	*content;
	char	*tmp;
	int		len;
	int		size;

	if (!(content = malloc(sizeof(char))))
		return (NULL);
	*content = '\0';
	size = 0;
	while ((len = read(fd, buf, 2048)) > 0)
	{
		if (!(tmp = malloc((size + len + 1) * sizeof(char))))
			break ;
		tmp = ft_strncpy(tmp, content, size);
		free(content);
		ft_strncpy(tmp + size, buf, len);
		content = tmp;
		size += len;
		content[size] = '\0';
	}
	if (len)
		free(content);
	return ((len) ? NULL : content);
}

char	*ft_file_load(char *path)
{
	char			*content;
	int				fd;

	fd = (path) ? open(path, O_RDONLY) : STDIN_FILENO;
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd);
	if (fd != STDIN_FILENO)
		close(fd);
	return (content);
}
