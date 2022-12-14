/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:31:49 by ldione            #+#    #+#             */
/*   Updated: 2022/03/07 18:53:11 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_hex_putnbr_upp(unsigned int hex, unsigned int count)
{
	char			*hex_c;
	unsigned int	hex_copy;

	hex_copy = hex;
	hex_c = "0123456789ABCDEF";
	while (hex_copy > 0)
	{
		count++;
		hex_copy /= 16;
	}
	if (hex >= 16)
	{
		ft_hex_putnbr_upp(hex / 16, 0);
	}
	ft_putchar((char)(hex_c[hex % 16]));
	if (hex == 0)
		count = 1;
	return (count);
}

unsigned int	ft_hex_putnbr_low(unsigned long long hex, unsigned int count)
{
	unsigned long long	hex_copy;
	char				*hex_c;

	hex_copy = hex;
	hex_c = "0123456789abcdef";
	if (hex >= 16)
	{
		ft_hex_putnbr_low(hex / 16, 0);
	}
	ft_putchar((char)(hex_c[hex % 16]));
	while (hex_copy > 0)
	{
		count++;
		hex_copy /= 16;
	}
	if (hex == 0)
		count = 1;
	return (count);
}

unsigned int	ft_check_opt(va_list params, const char *arg)
{
	if (*arg == 'c')
		return (ft_putchar(va_arg(params, int)));
	else if (*arg == 's')
		return (ft_putstr(va_arg(params, void *)));
	else if (*arg == 'p')
		return (ft_putptr(va_arg(params, uintptr_t)));
	else if (*arg == 'd')
		return (ft_putnbr(va_arg(params, int), 0));
	else if (*arg == 'i')
		return (ft_putnbr(va_arg(params, int), 0));
	else if (*arg == 'u')
		return (ft_putnbr_uns(va_arg(params, unsigned int), 0));
	else if (*arg == 'x')
		return (ft_hex_putnbr_low(va_arg(params, unsigned int), 0));
	else if (*arg == 'X')
		return (ft_hex_putnbr_upp(va_arg(params, unsigned int), 0));
	else if (*arg == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *arg, ...)
{
	unsigned int	sum;
	va_list			params;

	va_start(params, arg);
	sum = 0;
	if (!arg)
		return (0);
	while (*arg)
	{
		if (*arg == '%')
		{
			sum += (ft_check_opt(params, ++arg));
		}
		else
		{
			ft_putchar(*arg);
			sum++;
		}
		arg++;
	}
	va_end(params);
	return (sum);
}
