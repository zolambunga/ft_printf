#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
void	ft_reverse_hex_output(char *buffer, int start, int end);
int	ft_printhex(unsigned long value, int sign, char flag);
int	ft_putptr(unsigned long ptr);
int	ft_putnbr_decimal(int nbr, char flag);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_printf(const char *str, ...);

#endif
