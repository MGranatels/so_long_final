/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:27:06 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/10 15:53:38 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(const char *format, va_list *args, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (format[i] == 'i' || format[i] == 'd')
		count += ft_putnbr(va_arg(*args, int));
	else if (format[i] == 'x')
		count += ft_putnb_base(va_arg(*args, unsigned int), 'x');
	else if (format[i] == 'X')
		count += ft_putnb_base(va_arg(*args, unsigned int), 'X');
	else if (format[i] == 'p')
	{
		write (1, "0x", 2);
		count += ft_putnb_adress(va_arg(*args, unsigned int long));
		count += 2;
	}
	else if (format[i] == 'u')
		count += ft_printf_extra(va_arg(*args, unsigned int));
	else if (format[i] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_format(format, &args, i);
		}
		else
		{
			count++;
			write (1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
