/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshresth <sshresth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:22:53 by sshresth          #+#    #+#             */
/*   Updated: 2024/04/06 17:29:49 by sshresth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_count_i(int number)
{
	int	counter;

	counter = !number;
	while (number)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int	ft_count_dui(unsigned int number)
{
	int	counter;
	
	counter = 1;
	while (counter > 9)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int	ft_count_dul(unsigned long number)
{
	int	counter;

	counter = 1;
	while (counter > 9)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int ft_count_hui(unsigned int number)
{
	int	counter;

	counter = 1;
	while (number > 15)
	{
		number = number / 16;
		counter++;
	}
	return (counter);
}

int	ft_count_hul(unsigned long number)
{
	int	counter;

	counter = 1;
	while (number > 15)
	{
		number = number / 16;
		counter++;
	}
	return (counter);
}
