/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:27:51 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 10:38:36 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_printf	*s_data_initialize(t_printf *s_data)
{
	s_data->total_length = 0;
	s_data->width = 0;
	s_data->hash = 0;
	s_data->plus = 0;
	s_data->zero = 0; //set to false
	s_data->dot = 0; //set to false
	s_data->dash = 0; //set to false
	s_data->sign = 0; //set to false
	s_data->is_zero = 0; //set to false
	s_data->percent = 0; //set to false
	s_data->space = 0; //set to false
	return (s_data);
}

t_printf	*s_data_clear(t_printf *s_data)
{
	s_data->width = 0;
	s_data->hash = 0;
	s_data->plus = 0;
	s_data->zero = 0;
	s_data->dot = 0;
	s_data->dash = 0;
	s_data->sign = 0;
	s_data->is_zero = 0;
	s_data->percent = 0;
	s_data->space = 0;
	return (s_data);
}