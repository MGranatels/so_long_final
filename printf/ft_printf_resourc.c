/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resourc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:49:44 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/10 15:53:25 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int			count;
	long int	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putnb_base(unsigned int n, char x)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_putnb_base(n / 16, x);
		count += ft_putnb_base(n % 16, x);
	}
	else
	{
		if (n < 10)
			count += ft_putchar(n + '0');
		else
		{
			if (x == 'X')
				count += ft_putchar("0123456789ABCDEF"[n]);
			else
				count += ft_putchar("0123456789abcdef"[n]);
		}
	}
	return (count);
}

int	ft_putnb_adress(unsigned int long p)
{
	int	count;

	count = 0;
	if (p > 15)
	{
		count += ft_putnb_adress(p / 16);
		count += ft_putnb_adress(p % 16);
	}
	else
		count += ft_putchar("0123456789abcdef"[p]);
	return (count);
}
