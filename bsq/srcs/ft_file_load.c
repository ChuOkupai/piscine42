/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:14:34 by gdinet            #+#    #+#             */
/*   Updated: 2019/07/24 17:26:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

char	*ft_bufcpy(char *dest, char *src, int n)
{
	char *d;

	d = dest;
	while (n--)
		*d++ = *src++;
	return (dest);
}

char	*ft_file_read(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*content;
	char	*tmp;
	int		len;
	int		size;

	if (!(content = malloc(sizeof(char))))
		return (NULL);
	*content = '\0';
	size = 0;
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!(tmp = malloc((size + len + 1) * sizeof(char))))
			break ;
		tmp = ft_bufcpy(tmp, content, size);
		free(content);
		ft_bufcpy(tmp + size, buf, len);
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
	char	*content;
	int		fd;

	fd = (path) ? open(path, O_RDONLY) : STDIN_FILENO;
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd);
	if (fd != STDIN_FILENO)
		close(fd);
	return (content);
}
