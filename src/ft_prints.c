/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 05:08:59 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 10:38:29 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_dot(t_printf *s_data, int length)
{
	s_data->dot--;
	if (length > s_data->dot)
		length = s_data->dot;
	return (length);
}

static void	ft_left(t_printf *s_data, int length)
{
	s_data->width -= length;
	while (s_data->width-- > 0)
	{
		if (s_data->zero)
			s_data->total_length += write(1, "0", 1);
		else
			s_data->total_length += write(1, " ", 1);
	}
}

static void	ft_right(t_printf *s_data, size_t length)
{
	s_data->width -= length;
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

void	ft_prints(t_printf	*s_data)
{
	char	*str;
	int	length;

	str = va_arg(s_data->args, char *);
	if (!str)
	{
		s_data->total_length += write(1, "(null)", 6);
		return ;
	}
	length = (int)ft_strlen(str);
	if (s_data->dot)
		length = ft_dot(s_data, length);
	if (!s_data->dash && (s_data->zero || s_data->width))
		ft_left(s_data, length);
	s_data->total_length += write(1, str, length);
	if (s_data->width && s_data->dash)
		ft_right(s_data, length);
}
