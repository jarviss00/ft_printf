/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:04:37 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 10:38:22 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_left(t_printf *s_data)
{
	while (s_data->width-- > 0)
	{
		if (s_data->zero)
			s_data->total_length += write(1, "0", 1);
		else
			s_data->total_length += write(1, " ", 1);
	}
}

static void	ft_right(t_printf *s_data)
{
	while (s_data->width-- > 0)
		s_data->total_length += write(1, " ", 1);
}

void	ft_printc(t_printf *s_data)
{
	char	character;

	character = va_arg(s_data->args, int);
	if (!s_data->dash && (s_data->width || s_data->zero))
	{
		ft_left(s_data);
		s_data->width--;
	}
	s_data->total_length += write(1, &character, 1);
	if (s_data->width && s_data->dash)
	{
		ft_right(s_data);
		s_data->width--;
	}
}