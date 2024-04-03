/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:20:18 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/02 17:26:09 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_cs(const char *format, va_list args, int index)
{
	index++;
	if (format[index] == 'c')
		write(1, &(char){va_arg(args, int)}, 1);
	else if (format[index] == 's')
		index = ft_apply_str(args, index);
	return (index);
}