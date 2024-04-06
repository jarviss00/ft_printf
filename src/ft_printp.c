/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 05:09:06 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 11:11:19 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len(t_printf *s_data, int length)
{
	int	returned_length;

	if (s_data->dot == 1)
	{
		if (s_data->dot > length)
			returned_length = s_data->dot - 1;
		else
			returned_length = length;
	}
	else if (s_data->zero == 1)
	{
		if (s_data->width > length)
			returned_length = s_data->width - 2;
		else
			returned_length = length - 2;
	}
	else
		returned_length = length;
	return (returned_length);
}

static void	ft_zeros(t_printf *s_data, int len, unsigned long num)
{
	len = len - ft_count_hul(num);
	while (len-- > 0)
		s_data->total_length += write(1, "0", 1);
	
}

static void	ft_left(t_printf *s_data, int length)
{
	if (s_data->dash == 1)
		return ;
	s_data->width -= length + 2;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

static void ft_right(t_printf *s_data, int length)
{
	if (s_data->dash == 0)
		return ;
	s_data->width -= length + 2;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

void	ft_printp(t_printf	*s_data)
{
	int				length;
	char			character;
	unsigned long	number;
	unsigned long	power;
	
	number = va_arg(s_data->args, unsigned long);
	length = ft_len(s_data, ft_count_hul(number));
	ft_left(s_data, length);
	s_data->total_length += write(1, "0x", 2);
	ft_zeros(s_data, length, number);
	power = 1;
	while (number / power / 16)
		power *= 16;
	while (power != 0)
	{
		character = number / power;
		if (character >= 0 && character <= 9)
			character += '0';
		else
			character += 'W';
		s_data->total_length += write(1, &character, 1);
		number %= power;
		power /= 16;
	}
	ft_right(s_data, length);
}