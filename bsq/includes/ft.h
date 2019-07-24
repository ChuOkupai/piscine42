/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 04:52:47 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/24 21:03:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define MAX_LINES		12000
# define BUFFER_SIZE	5800000
# define MIN(A, B)		((A < B) ? A : B)

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_map
{
	char	*content;
	char	*matrix;
	char	empty;
	char	full;
	char	obstacle;
	t_point	size;
}				t_map;

typedef struct	s_square
{
	t_point	coords;
	int		size;
}				t_square;

char			*ft_file_load(char *path);

int				ft_is_valid(t_map *m);

void			ft_find_biggest_square(t_map *m, t_square *s);

#endif
