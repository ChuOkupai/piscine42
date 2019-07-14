/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:52:27 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/11 15:52:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct		s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}					t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void				ft_show_tab(struct s_stock_str *par);

#endif
