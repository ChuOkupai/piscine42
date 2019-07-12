/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 05:33:05 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/12 10:41:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int		ft_wordlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_separator(str + i, charset))
		i++;
	return (i);
}

int		ft_wordcount(char *str, char *charset)
{
	int i;
	int w;

	w = 0;
	while (*str)
	{
		while (*str && ft_is_separator(str, charset))
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			w++;
	}
	return (w);
}

char	*ft_wordcpy(char *src, int n)
{
	char	*dest;

	if (!(dest = malloc((n + 1) * sizeof(char))))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**t;
	int		size;
	int		i;
	int		n;

	size = ft_wordcount(str, charset);
	if (!(t = malloc((size + 1) * sizeof(char*))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && ft_is_separator(str, charset))
			str++;
		n = ft_wordlen(str, charset);
		if (!(t[i] = ft_wordcpy(str, n)))
			return (NULL);
		str += n;
	}
	t[size] = 0;
	return (t);
}
