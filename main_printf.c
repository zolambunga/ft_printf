/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:47:27 by zombunga          #+#    #+#             */
/*   Updated: 2024/08/15 15:29:11 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(int ac, char *av[])
{
	(void)ac;
	int	nbr;
	char *null_str = NULL;
	
	//null_str = NULL;
	nbr = 0;
	
	nbr = printf("|--.%#Xs|", 0);
	printf("\ntamanho: %d\n", nbr);

	nbr = ft_printf("|--.%#Xs|", 0);;
	printf("\ntamanho: %d\n", nbr);

	/*nbr = printf("%c | %s | %p | %d | %i | %u | %x | %X | %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("\ntamanho: %d\n", nbr);
	nbr = ft_printf("%c | %s | %p | %d | %i | %u | %x | %X | %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("\ntamanho: %d\n", nbr);*/
	/*nbr = printf("Flag 'd'-> %%d : |%d|\n", 42);
	printf("tamanho: %d\n", nbr);

	nbr = printf("Flag '-'-> %%-10s : |%-10s|\n", "left");
   	printf("tamanho: %d\n", nbr);

	nbr = printf("Flag '0' -> %%05d : |%05d|\n", 42);
    	printf("tamanho: %d\n", nbr);

	nbr = printf("Flag '#' -> %%#x : |%#x|\n", 255);
    	printf("tamanho: %d\n", nbr);
    	
    	nbr = printf("Flag '#' -> %%#X : |%#X|\n", 255);
    	printf("tamanho: %d\n", nbr);

	nbr = printf("Flag '+' -> %%+d : |%+d|\n", 42);
    	printf("tamanho: %d\n", nbr);

	nbr = printf("Flag ' ' -> %% d : |% d|\n", 42);
    	printf("tamanho: %d\n", nbr);

        nbr = printf("Flag '+' -> %%+i : |%+i|\n", 42);
	printf("tamanho: %d\n", nbr);

        nbr = printf("Flag ' ' -> %% i : |% i|\n", 42);
	printf("tamanho: %d\n", nbr);


	nbr = printf("Largura de Campo -> %%10d : |%10d|\n", 42);
    	printf("tamanho: %d\n", nbr);

	nbr = printf("Precisão -> %%.5d : |%.5d|\n", 42);
	printf("tamanho: %d\n", nbr);

	nbr = printf("Combinação -> %%+08d : |%+08d|\n", 42);
	printf("tamanho: %d\n", nbr);*/
//	nbr = printf("Combinação -> %%+c : |%+c|\n", 'j');
//	printf("tamanho: %d\n", nbr);

	return (0);
}
