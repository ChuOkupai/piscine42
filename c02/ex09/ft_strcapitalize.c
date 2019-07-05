/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:42:24 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/05 04:12:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (ft_isdigit(*s) || ft_islower(*s) || ft_isupper(*s))
		{
			if (ft_isdigit(*s))
				while (ft_isdigit(s[1]))
					s++;
			else if (ft_islower(*s))
				*s -= 32;
			while (ft_islower(*(++s)) || ft_isupper(*s))
				if (ft_isupper(*s))
					*s += 32;
		}
		else
			s++;
	}
	return (str);
}
