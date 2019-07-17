/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:32:41 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 22:44:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_display_file(char *path);

void	ft_putchar_fd(char c, int fd);

void	ft_puterr(char *bin, char *path, char *error);

void	ft_putstr_fd(char *str, int fd);

int		ft_strcmp(char *s1, char *s2);

int		ft_strlen(char *str);

#endif
