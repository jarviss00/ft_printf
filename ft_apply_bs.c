/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_bs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:18:18 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/02 17:19:38 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_apply_bs(const char *format, int index)
{
	index++;
	if (format[index] == 'n')
		write(1, "\n", 1);
	return (index);
}