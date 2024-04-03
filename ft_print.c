/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:54:41 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/03 22:42:34 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}

int	ft_print_p(unsigned	long int num)
{
	int	length;

	length = 0;
	while (num >= 16)
	{
		length += ft_print_p(num / 16);
		length += ft_print_p(num % 16);
	}
	if (num < 16)
	{
		if (num < 10)
			length = ft_print_c(num + 48);
		else
			length = ft_print_c(num + 87);
	}
	return (length);
}

int	ft_print_di(int num)
{
	int	length;

	length = 0;
	if (num < 0)
	{
		length = write(1, "-", 1);
		num *= -1;
	}
	else if (num >= 10)
	{
		length = ft_print_di(num / 10);
		length += ft_print_di(num % 10);
	}
	else if (num < 10)
		length = ft_print_c(num + 48);
	return (length);
}

int	ft_print_u(unsigned int num)
{
	int	length;

	length = 0;
	if (num >= 10)
	{
		length = ft_print_u(num / 10);
		length += ft_print_di(num % 10);
	}
	else if (num < 10)
		length = ft_print_c(num + 48);
	return (length);
}

int	ft_print_x(unsigned int num, int flag)
{
	int	length;

	length = 0;
	if (num < 16)
	{
		if (num >= 10)
		{
			if (flag == 1)
				length = ft_print_c(num + 87);
			else
				length = ft_print_c(num + 55);
		}
		else if (num < 10)
		{
			length = ft_print_c(num + 48);
		}
	}
	return (length);
}
