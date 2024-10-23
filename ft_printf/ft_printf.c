/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:33:20 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/24 18:06:36 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_look_print(va_list all, char *arg, int i)
{
	int	count;

	count = 0;
	if (arg[i] == 'c')
		count += ft_putchar(va_arg(all, int));
	else if (arg[i] == 's')
		count += ft_putstr(va_arg(all, char *));
	else if (arg[i] == 'p')
	{
		count += ft_putstr("0x");
		count += ft_voidhexa(va_arg(all, unsigned long));
	}
	else if (arg[i] == 'd' || arg[i] == 'i')
		count += ft_putnbr(va_arg(all, int));
	else if (arg[i] == 'u')
		count += ft_putnbru(va_arg(all, unsigned int));
	else if (arg[i] == 'x')
		count += ft_puthexamin(va_arg(all, unsigned int));
	else if (arg[i] == 'X')
		count += ft_puthexamaj(va_arg(all, unsigned int));
	else if (arg[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *arg, ...)
{
	va_list	all;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(all, arg);
	while (arg[i] != '\0')
	{
		if (arg[i] == '%' && arg[i + 1] != '\0')
		{
			i++;
			count += ft_look_print(all, (char *)arg, i);
		}
		else
		{
			write (1, &arg[i], 1);
			count++;
		}
		i++;
	}
	va_end(all);
	return (count);
}
