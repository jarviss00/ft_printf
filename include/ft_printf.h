/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:30:49 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 11:34:36 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H	
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_printf
{
	va_list	args; //arg to print out
	int		total_length; // total length (return value)
	int		width; //width
	int		hash; // #
	int		plus; // #
	int		zero; //zero padding
	int		dot; // .
	int		dash; // -
	int		sign; // positive or negative number
	int		is_zero; //is number zero
	int		percent; // %
	int		space; // space flag ' '
}	t_printf;

t_printf	*s_data_initialize(t_printf *s_data);
t_printf	*s_data_clear(t_printf *s_data);

int			ft_apply_format(t_printf *s_data, const char *format, int f_index);
int			ft_apply_flags(t_printf	*s_data, const char *format, int f_index);

int			ft_count_i(int number);
int			ft_count_dui(unsigned int number);
int			ft_count_dul(unsigned long number);
int			ft_count_hui(unsigned int number);
int			ft_count_hul(unsigned long number);

int			ft_printf(const char *format, ...);
void		ft_printc(t_printf *s_data);
void		ft_prints(t_printf	*s_data);
void		ft_printp(t_printf	*s_data);
void		ft_printi(t_printf *s_data);

#endif