/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:10:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/20 20:07:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_fct(int c, va_list ap)
{
	int	tot;

	tot = 0;
	if (c == 'c')
		tot += ft_putchar(va_arg(ap, unsigned int));
	else if (c == 's')
		tot += putstr(va_arg(ap, char *));
	else if (c == 'p')
		tot += ft_itoa_adr(va_arg(ap, unsigned long));
	else if (c == 'd')
		tot += ft_itoa(va_arg(ap, int), "0123456789", 10);
	else if (c == 'i')
		tot += ft_itoa(va_arg(ap, int), "0123456789", 10);
	else if (c == 'u')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789", 10);
	else if (c == 'x')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		tot += ft_itoa(va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	else
		tot += print_percent();
	return (tot);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			tot;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	tot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			tot += get_fct(str[i + 1], ap);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			tot++;
			i++;
		}
	}
	va_end(ap);
	return (tot);
}

/*#include <stdio.h>
int main(void)
{
    int a = -2147483645 ;
    int *ptr = &a;
    ft_printf("ft_printfの%%p: %p\n", (void *)ptr);
    printf("printfの%%p: %p\n", (void *)ptr);
        
    ft_printf("PachuruPachuruPachuru %u\n", "adal-bos", a, a);
    printf("PachuruPachuruPachuru%u\n", "adal-bos", a, a);

    ft_printf("%%%%%%%%%%\n");
    printf("%%%%%%%%%%\n");
    
    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);

    ft_printf(" %x \n", INT_MIN);
    printf(" %x \n",  INT_MIN);

    a = 42;


    ft_printf("test x: %x\ntest X: %X\n", a, a);
    printf("test x: %x\ntest X: %X\n", a, a);

    ft_printf("INT_MIN: %x\n", INT_MIN);
    printf("INT_MIN: %x\n", INT_MIN);

    ft_printf("INT_MAX: %x\n", INT_MAX);
    printf("INT_MAX: %x\n", INT_MAX);

    ft_printf("UINT_MAX: %x\n", UINT_MAX);
    printf("UINT_MAX: %x\n", UINT_MAX);

    ft_printf("Large positive int: %x\n", INT_MAX);
    printf("Large positive int: %x\n", INT_MAX);

    ft_printf("Large negative int: %x\n", INT_MIN);
    printf("Large negative int: %x\n", INT_MIN);

    printf("%d\n", ft_printf("Zero: %x\n", 10));
    printf("%d\n", printf("Zero: %x\n", 10));
    
    printf("%d\n", ft_printf("Zero: %X\n", -10));
    printf("%d\n", printf("Zero: %X\n", -10));

    ft_printf("Simple hex: %x\n", 0xABCD);
    printf("Simple hex: %x\n", 0xABCD);

    void *ptr2 = NULL;
    ft_printf("%p\n", (void *)ptr2);
    printf("%p\n", (void *)ptr2);
    printf("%d\n",ft_printf("%p", (void *)ptr2));
    printf("%d\n",printf("%p", (void *)ptr2));
}*/
