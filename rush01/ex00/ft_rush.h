/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:03:57 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/14 21:08:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_get_size(char *str);

char	**ft_init_tab(char *str, int size);

int		ft_solve(char **tab, int size);

void	ft_print_tab(char **tab, int size);

void	ft_destroy_tab(char **tab, int size);

int		ft_height_col(char **tab, int x, int delta, int size);

int		ft_height_row(char **tab, int y, int delta, int size);

int		ft_is_duplicate(char **tab, int x, int y, int size);

#endif
