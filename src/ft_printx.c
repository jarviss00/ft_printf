/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 05:06:59 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/09 17:54:58 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len(t_printf *s_data, int count)
{
	int	length;

	if (s_data->dot == 1)
	{
		if (s_data->dot > count)
			length = s_data->dot - 1;
		else
			length = count;
	}
	else if (s_data->zero == 1)
	{
		if (s_data->width > count)
			length = s_data->width;
		else
			length = count;
	}
	else
		length = count;
	if (s_data->hash == 1)
		length += 2;
	return (length);
}

static void	ft_left(t_printf *s_data, unsigned int argument, char character, int length)
{
	if (s_data->dash == 0)
	{
		s_data->width = length;
		while (s_data->width-- > 0)
			s_data->total_length += write(1, " ", 1);
	}
	if (s_data->hash && argument)
	{
		if (character == 'x')
			s_data->total_length += write(1, "0x", 2);
		else
			s_data->total_length += write(1, "0X", 2);
	}
	ft_zeros(s_data, argument, length);
}

static void	ft_zeros(t_printf *s_data, unsigned int argument, int length)
{
	length -= ft_count_hui(argument);
	if (s_data->hash)
		length -= 2;
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

void	ft_printx(char flag, t_printf *s_data)
{
	int				length;
	char			character;
	unsigned int	argument;
	unsigned int	power;

	argument = va_arg(s_data->args, unsigned long);
	length = ft_len(s_data, ft_count_hui(argument));
	ft_left(s_data, argument, flag, length);
	while (argument / power / 16)
		power *= 16;
	while (power)
	{
		character = argument / power + '0';
		if (!(character >= '0' && character <= '9'))
		{
			character += 7;
			if (flag == 'x')
				character += 32;
		}
		s_data->total_length += write(1, &character, 1);
		argument %= power;
		power /= 16;
	}
	ft_handle_right_align(s_data, length);
}