/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:05:10 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 11:35:37 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print(t_printf *s_data, int length, int sign)
{
	int	returned_length;

	if (s_data->dot == 1)
	{
		if (s_data->dot > length)
			returned_length = (s_data->dot + sign) - 1;
		else
			returned_length = length;
	}
	else if (s_data -> zero == 1)
	{
		if (s_data->width > length)
			returned_length = s_data->width;
		else
			returned_length = length;
	}
	else
	{
		returned_length = length;
		if (sign)
			returned_length++;
	}
	return (returned_length);
}

static void	ft_left(t_printf *s_data, int length)
{
	s_data->width -= length;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

static void	ft_zeros(t_printf *s_data,  int length, int sign, int n)
{
	length = length - ft_count_i(n);
	length--;
	if (sign)
		s_data->total_length += write(1, "-", 1);
	else if (s_data->plus)
		s_data->total_length += write(1, "+", 1);
	else if (s_data->space)
		s_data->total_length += write(1, " ", 1);
	else
		length++;
	while (length-- > 0)
		s_data->total_length += write(1, "0", 1);
}

static void	ft_right(t_printf *s_data, int length)
{
	if (s_data->dash == 0)
		return ;
	s_data->width -= length;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

void	ft_printi(t_printf *s_data)
{
	int				number;
	int				sign;
	int				length;
	char			character;
	unsigned int	power;

	number = va_arg(s_data->args, int);
	sign = 0;
	power = 1;
	if (number < 0 && sign++)
		number = -number;
	length = ft_print(s_data, ft_count_i(number), sign);
	if (s_data->dash == 0)
		ft_left(s_data, length);
	ft_zeros(s_data, length, sign, number);
	while (number / power / 10)
		power *= 10;
	while (power)
	{
		character = number / power + '0';
		s_data->total_length += write(1, &character, 1);
		number %= power;
		power /= 10;
	}
	ft_right(s_data, length);
}