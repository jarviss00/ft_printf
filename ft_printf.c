/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:06:12 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/03 22:43:29 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		index;
	int		length;
	va_list	args;

	index = 0;
	length = 0;
	va_start(args, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			length = ft_apply(args, str[index + 1]);
			index++;
		}
		else
		{
			write(1, &str[index], 1);
			index++;
		}
		index++;
	}
	va_end(args);
	return (length);
}

int	ft_apply(va_list args, const char format)
{
	int	length;
	
	length = 0;
	if (format == 'c')
		length = ft_print_c(va_arg(args, int));
	else if (format == 's')
		length = ft_print_s(va_arg(args, char *));
	else if (format == 'p')
		length = ft_print_p((unsigned long)va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length = ft_print_di(va_arg(args, int));
	else if (format == 'u')
		length = ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x')
		length = ft_print_x(va_arg(args, unsigned int), 1);
	else if (format == 'X')
		length = ft_print_x(va_arg(args, unsigned int), 2);
	else if (format == '%')
	{
		length = write(1, "%", 1);
	}
	return (length);
}

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}