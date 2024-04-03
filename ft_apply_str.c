/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:24:09 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/02 17:32:11 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_str(va_list args, int index)
{
	size_t	counter;
	const char	*str;

	counter = 0;
	str = (char *)va_arg(args, char *);
	while (counter < ft_strlen(str))
	{
		write(1, &str[counter], 1);
		counter++;	
	}
	index += counter;
	return (index);
}
