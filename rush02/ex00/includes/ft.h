/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:38:33 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 21:48:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_check_args(int argc, char **argv, char **path, char **value);

char	*ft_file_load(char *path);

int		ft_is_valid(char *value);

long	ft_atol(char *str);

int		ft_isdigit(char c);

int		ft_isprint(char c);

int		ft_isspace(char c);

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

#endif
