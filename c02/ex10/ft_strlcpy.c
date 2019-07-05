/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:11:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/05 07:02:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = ft_strlen(src);
	if (i + 1 < size)
	{
		j = -1;
		while (++j < i + 1)
			dest[j] = src[j];
	}
	else if (size)
	{
		j = -1;
		while (++j < size - 1)
			dest[j] = src[j];
		dest[j] = '\0';
	}
	return (i);
}
