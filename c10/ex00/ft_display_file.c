/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:17:46 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/15 16:45:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(char *path)
{
	char	buf[2048];
	int		fd;
	int		len;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((len = read(fd, buf, 2048)) > 0)
		write(1, buf, len);
	close(fd);
	return ((len) ? -1 : 0);
}
