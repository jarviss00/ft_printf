/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:49:59 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 11:13:47 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_apply_flags(t_printf	*s_data, const char *format, int f_index)
{
	while (!ft_strchr("cspdiuxX%", format[f_index]))
	{
		if (format[f_index] == '.' && ++f_index)
		{
			while (format[f_index] >= '0' && format[f_index] <= '9')
				s_data->dot = s_data->dot * 10 + (format[f_index] - '0');
			s_data->dot++;
		}
		else if (format[f_index] == '-' && ++f_index)
			s_data->dash = 1;
		else if (format[f_index] == '0' && ++f_index)
			s_data->zero = 1;
		else if (format[f_index] == '#' && ++f_index)
			s_data->hash = 1;
		else if (format[f_index] == ' ' && ++f_index)
			s_data->space = 1;
		else if (format[f_index] == '+' && ++f_index)
			s_data->plus = 1;
		else if (format[f_index] >= '1' && format[f_index] <= '9')
			while (format[f_index] >= '0' && format[f_index] <= '9')
				s_data->width = s_data->width * 10 + (format[f_index] - '0');
	}
	return (ft_apply_format(s_data, format, f_index));
}

int	ft_apply_format(t_printf *s_data, const char *format, int f_index)
{
	if (format[f_index] == 'c')
		ft_printc(s_data);
	else if (format[f_index] == 's')
		ft_prints(s_data);
	else if (format[f_index] == 'p')
		ft_printp(s_data);
	else if (format[f_index] == 'd' || format[f_index] == 'i')
		ft_printi(s_data);
	//else if (format[f_index] == 'u')
		//ft_printu(s_data);
	//else if (format[f_index] == 'x' || format[f_index] == 'X')
		//ft_printx(format[f_index], s_data);
	else if (format[f_index] == '%')
		s_data->total_length += write(1, "%", 1);
	s_data_clear(s_data);
	return (f_index);
}
