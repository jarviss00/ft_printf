/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:05:15 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/03 20:41:21 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_apply(va_list args, const char format);
int	ft_print_c(int c);
int ft_print_s(char *str);
int	ft_print_p(unsigned	long int num);
int	ft_print_di(int	num);
int	ft_print_u(unsigned int num);
int	ft_print_x(unsigned int num, int flag);

#endif