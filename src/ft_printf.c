/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:30:52 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 10:38:24 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	*s_data;
	int			index;
	int			returned_length;

	s_data = (t_printf *)malloc(sizeof(t_printf));
	if (s_data == NULL)
		return (-1);
	s_data_initialize(s_data);
	va_start(s_data->args, format);
	index = -1; //this helps in the while loop condition with prefix increment of index
	returned_length = 0;
	while (format[++index])
	{
		if (format[index] == '%')
			index = ft_apply_flags(s_data, format, index + 1); //index + 1 = the char after %
		else
			returned_length += write(1, &format[index], 1);
	}
	va_end(s_data->args);
	returned_length += s_data->total_length;
	free(s_data);
	return (returned_length);
}
