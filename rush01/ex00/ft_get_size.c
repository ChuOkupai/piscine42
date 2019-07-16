/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:02:06 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/14 21:20:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_valid(char *str, int size)
{
	int i;
	int j;

	i = -1;
	j = size / 4;
	while (++i < size)
	{
		if (*str < '1' || *str > j + '0')
			return (0);
		str += 2;
	}
	return (j);
}

int		ft_get_size(char *str)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			size++;
		else
			return (0);
		if (str[++i] == ' ' && !str[++i])
			return (0);
	}
	if (size != 16)
		return (0);
	return (ft_is_valid(str, size));
}
