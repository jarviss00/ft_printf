/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 05:08:45 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/09 17:30:09 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len(t_printf *s_data, int length)
{
	int	returned_length;

	if (s_data->dot)
	{
		if (s_data->dot > length)
			returned_length = s_data->dot - 1;
		else
			returned_length = length;
	}
	else if (s_data->zero)
	{
		if (s_data->width > length)
			returned_length = s_data->width;
		else
			returned_length = length;
	}
	else
		returned_length = length;
	return (returned_length);
}

static void	ft_left(t_printf *s_data, int print_len)
{
	s_data->width -= print_len;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

static void	ft_zeros(t_printf *s_data, int length, unsigned int number)
{
	length = length - ft_count_dui(number);
	while (length-- > 0)
		s_data->total_length += write(1, "0", 1);
}

static void	ft_right(t_printf *s_data, int length)
{
	if (!s_data->dash)
		return ;
	s_data->width -= length;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

void	ft_printu(t_printf	*s_data)
{
	int				length;
	char			character;
	unsigned int	number;
	unsigned int	power;

	number = va_arg(s_data->args, unsigned int);
	power = 1;
	length = ft_len(s_data, ft_count_dui(number));
	if (!s_data->dash)
		ft_left(s_data, length);
	ft_zeros(s_data, length, number);
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