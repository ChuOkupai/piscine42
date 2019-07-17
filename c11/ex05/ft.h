/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:21:58 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/17 05:45:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

enum	e_op
{
	op_sum,
	op_sub,
	op_div,
	op_mul,
	op_mod,
};

int		ft_sum(int a, int b);

int		ft_sub(int a, int b);

int		ft_div(int a, int b);

int		ft_mul(int a, int b);

int		ft_mod(int a, int b);

int		ft_atoi(char *str);

void	ft_putchar(char c);

void	ft_putstr(char *str);

#endif
