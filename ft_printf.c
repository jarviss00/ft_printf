/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:06:12 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/02 17:22:52 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;

	va_start(args, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
			index = ft_apply_cs(format, args, index);
		else if (format[index] == '\\')
			index = ft_apply_bs(format, index);
		else
			write(1, &format[index], 1);
		index++;
	}
	return (index);
}