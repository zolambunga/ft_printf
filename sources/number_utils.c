/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:39:31 by zombunga          #+#    #+#             */
/*   Updated: 2024/08/15 18:42:12 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len += ft_putnbr_unsigned(nbr / 10);
	len += ft_putchar("0123456789"[nbr % 10]);
	return (len);
}

int	ft_putnbr_decimal(int nbr, char flag)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (flag == '+' && nbr >= 0)
		len += ft_putchar('+');
	else if (flag == ' ' && nbr >= 0)
		len += ft_putchar(' ');

	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		len += ft_putnbr_decimal(nbr / 10, 'a');

	len += ft_putchar("0123456789"[nbr % 10]);
	return (len);
}
