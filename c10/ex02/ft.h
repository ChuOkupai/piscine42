/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:32:41 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 23:18:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_atoi(char *str);

int		ft_display_file(char *path);

void	ft_putchar_fd(char c, int fd);

void	ft_puterr(char *bin, char *path, char *error);

void	ft_putstr_fd(char *str, int fd);

int		ft_strcmp(char *s1, char *s2);

int		ft_strlen(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		ft_tail(char *path, unsigned int n, int count, int print_path);

#endif
