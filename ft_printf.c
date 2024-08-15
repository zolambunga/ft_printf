/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:47:27 by zombunga          #+#    #+#             */
/*   Updated: 2024/08/15 18:37:42 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	formater(const char *str, int *total, va_list *ap, char flag)
{
	if (*str == 'c')
		*total += ft_putchar(va_arg(*ap, int));
	else if (*str == 's')
		*total += ft_putstr(va_arg(*ap, char *));
	else if (*str == 'p')
		*total += ft_putptr(va_arg(*ap, unsigned long));
	else if (*str == 'd' || *str == 'i')
		*total += ft_putnbr_decimal(va_arg(*ap, int), flag);
	else if (*str == 'u')
		*total += ft_putnbr_unsigned(va_arg(*ap, unsigned int));
	else if (*str == 'x')
		*total += ft_printhex(va_arg(*ap, unsigned long), 0, flag);
	else if (*str == 'X')
		*total += ft_printhex(va_arg(*ap, unsigned long), 1, flag);
	else if (*str == '%')
		*total += ft_putchar('%');
}

static void	process_flags(const char *str, char flag, int *total, va_list *ap)
{
	if(flag == '+' || (flag == ' ' && *(str+1) == 'd'))
	{
		str++;
		formater(str, total, ap, flag);
	}
	else if((flag == '#' && *(str+1) == 'x') || *(str+1) == 'X')
	{
		str++;
		formater(str, total, ap, flag);
	}
}

int	ft_printf(const char *str, ...)
{
	int	total;

	total = 0;
	va_list	ap;
	va_start(ap, str);
	while(*str)
	{
		if(*str == '%')
		{
			str++;
			if(*str == '+' || *str == ' ' || *str == '#')
			{
				str += 2;
				process_flags(str-2, *(str-2), &total, &ap);
			}
			else
			{
				str++;
				formater((str-1), &total, &ap, 'a');
			}
		}
		else
		{
			total += ft_putchar(*str);
			str++;
		}
	}
	va_end(ap);
	return (total);
}

/*int	main(int ac, char *av[])
{
	(void)ac;
	int	nbr;

	nbr = 0;
	nbr = ft_printf("F.cool man |%#x| noob |% d| pro |%+d|", 42, 42, 42);
	printf("\ntotal: %d\n", nbr);
	nbr = printf("V.cool man |%#x| noob |% d| pro |%+d|", 42, 42, 42);
	printf("\ntotal: %d\n", nbr);
	
	nbr = ft_printf("F.cool man |%c| noob |%x| pro |%s|", 'a', 42, "Jesus é Deus!");
	printf("\ntotal: %d\n", nbr);
	nbr = printf("V.cool man |%c| noob |%x| pro |%s|", 'a', 42, "Jesus é Deus!");
	printf("\ntotal: %d\n", nbr);
	
	nbr = ft_printf("F.cool man |%%| noob |%i| pro |%+i|", 42, -1);
	printf("\ntotal: %d\n", nbr);
	nbr = printf("V.cool man |%%| noob |%i| pro |%+i|", 42, -1);
	printf("\ntotal: %d\n", nbr);
	return (0);
}*/
