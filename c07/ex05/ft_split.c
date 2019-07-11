/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 05:33:05 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/11 08:01:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int		ft_is_separator(char *str, char *charset)
{
	if (!*charset)
		return (0);
	while (*charset && *str == *charset)
	{
		str++;
		charset++;
	}
	return (*charset == '\0');
}

int		ft_wordcount(char *str, char *charset, int charset_len)
{
	int i;
	int w;

	if (!*charset)
		return (*str != '\0');
	w = 0;
	while (*str)
	{
		while (*str && ft_is_separator(str, charset))
			str += charset_len;
		i = 0;
		while (str[i] && !ft_is_separator(str + i, charset))
			i++;
		if (i)
			w++;
		str += i;
	}
	return (w);
}

char	*ft_wordcpy(char **str, char *charset, int charset_len)
{
	char	*s;
	int		i;
	int		j;

	while (**str && ft_is_separator(*str, charset))
		*str += charset_len;
	i = 0;
	while ((*str)[i] && !ft_is_separator((*str) + i, charset))
		i++;
	if (!(s = malloc((i + 1) * sizeof(char*))))
		return (NULL);
	j = i;
	s[i] = '\0';
	while (i-- > 0)
		s[i] = (*str)[i];
	*str += j;
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	char	**t;
	int		charset_len;
	int		size;
	int		i;

	charset_len = ft_strlen(charset);
	size = ft_wordcount(str, charset, charset_len);
	if (!(t = malloc((size + 1) * sizeof(char*))))
		return (NULL);
	i = -1;
	while (++i < size)
		if (!(t[i] = ft_wordcpy(&str, charset, charset_len)))
			return (NULL);
	t[i] = NULL;
	return (t);
}
