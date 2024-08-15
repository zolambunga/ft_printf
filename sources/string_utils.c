/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:42:25 by zombunga          #+#    #+#             */
/*   Updated: 2024/08/15 18:43:18 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c,1));
}

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

void	ft_reverse_hex_output(char *buffer, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
}

int	ft_printhex(unsigned long value, int sign, char flag)
{
	int	len;
	int	i;
	int	start;
	int	end;
	char	buffer[17];

	i = 0;
	len = 0;
	if(flag == '#' && sign == 0)
		len += ft_putstr("0x");
	else if(flag == '#' && sign == 1)
		len += ft_putstr("0X");
	if (value == 0)
		return (ft_putchar('0'));
	while (value > 0)
	{
		if (sign == 0)
			buffer[i++] = "0123456789abcdef"[value%16];
		else if (sign == 1)
			buffer[i++] = "0123456789ABCDEF"[value%16];
		value /= 16;
	}
	buffer[i] = '\0';
	start = 0;
	end = i - 1;
	ft_reverse_hex_output(buffer, start, end);
	len += ft_putstr(buffer);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if(!ptr)
		return(ft_putstr("(nil)"));
	len += ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar('0');
	else
		len += ft_printhex(ptr, 0, 'a');
	return (len);
}
