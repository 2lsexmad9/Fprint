/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adal-bos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:06:39 by adal-bos          #+#    #+#             */
/*   Updated: 2024/10/28 01:49:54 by adal-bos         ###   ########.fr       */
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
    int a = -2147483645;
    int *ptr = &a;

    // Print the memory address of variable 'a'
    printf("Memory address of 'a':\n");
    printf("ft_printf: %p\n", (void *)ptr);
    printf("printf: %p\n", (void *)ptr);

    // Print the unsigned integer value of 'a'
    printf("Unsigned integer value of 'a':\n");
    printf("ft_printf: %u\n", a);
    printf("printf: %u\n", a);

    // Print percentage signs
    printf("Percentage signs:\n");
    printf("ft_printf: %%\n");
    printf("printf: %%\n");

    // Print the hexadecimal value of 'a' in lowercase and uppercase
    printf("Hexadecimal value of 'a':\n");
    printf("ft_printf: lowercase: %x, uppercase: %X\n", a, a);
    printf("printf: lowercase: %x, uppercase: %X\n", a, a);

    // Print the minimum integer value in hexadecimal
    printf("Minimum integer value in hexadecimal:\n");
    printf("ft_printf: %x\n", INT_MIN);
    printf("printf: %x\n", INT_MIN);

    // Set 'a' to 42
    a = 42;

    // Print the hexadecimal value of 'a' in lowercase and uppercase
    printf("Hexadecimal value of 'a' (42):\n");
    printf("ft_printf: lowercase: %x, uppercase: %X\n", a, a);
    printf("printf: lowercase: %x, uppercase: %X\n", a, a);

    // Print the minimum and maximum integer values in hexadecimal
    printf("Integer limits in hexadecimal:\n");
    printf("ft_printf: Minimum: %x, Maximum: %x\n", INT_MIN, INT_MAX);
    printf("printf: Minimum: %x, Maximum: %x\n", INT_MIN, INT_MAX);

    // Print the maximum unsigned integer value in hexadecimal
    printf("Maximum unsigned integer value in hexadecimal:\n");
    printf("ft_printf: %x\n", UINT_MAX);
    printf("printf: %x\n", UINT_MAX);

    // Print large positive and negative integers in hexadecimal
    printf("Large integer values in hexadecimal:\n");
    printf("ft_printf: Positive: %x, Negative: %x\n", INT_MAX, INT_MIN);
    printf("printf: Positive: %x, Negative: %x\n", INT_MAX, INT_MIN);

    // Print N of characters printed and the hexadecimal representation of 10
    printf("Number of characters printed and hexadecimal value of 10:\n");
    printf("ft_printf: Count: %d, Hex: %x\n", ft_printf("Zero: %x\n", 10), 10);
    printf("printf: Count: %d, Hex: %x\n", printf("Zero: %x\n", 10), 10);

    // Print N of characters printed and the hexadecimal representation of -10
    printf("Number of characters printed and hexadecimal value of -10:\n");
    printf("ft_printf: Count: %d, Hex: %X\n", ft_printf("Zero: %X\n", -10), -10);
    printf("printf: Count: %d, Hex: %X\n", printf("Zero: %X\n", -10), -10);

    // Print a simple hexadecimal value
    printf("Simple hexadecimal value:\n");
    printf("ft_printf: %x\n", 0xABCD);
    printf("printf: %x\n", 0xABCD);

    // Print the address of a null pointer
    void *ptr2 = NULL;
    printf("Null pointer address:\n");
    printf("ft_printf: %p\n", ptr2);
    printf("printf: %p\n", ptr2);
    printf("ft_printf: Count: %d\n", ft_printf("%p", ptr2));
    printf("printf: Count: %d\n", printf("%p", ptr2));
}*/
