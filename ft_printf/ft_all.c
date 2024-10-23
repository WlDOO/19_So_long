/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:55:51 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/22 18:22:44 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_voidhexa(unsigned long nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += ft_voidhexa(nbr / 16);
		i += ft_voidhexa(nbr % 16);
	}
	else
	{
		i += ft_putchar(hexa[nbr % 16]);
	}
	return (i);
}

int	ft_puthexamin(unsigned int nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += ft_puthexamin(nbr / 16);
		i += ft_puthexamin(nbr % 16);
	}
	else
	{
		i += ft_putchar(hexa[nbr % 16]);
	}
	return (i);
}

int	ft_puthexamaj(unsigned int nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		i += ft_puthexamaj(nbr / 16);
		i += ft_puthexamaj(nbr % 16);
	}
	else
	{
		i += ft_putchar(hexa[nbr % 16]);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
		count++;
	}
	if (nbr > 9)
	{
		count += ft_putnbr((nbr / 10));
		count += ft_putnbr((nbr % 10));
	}
	else
	{
		nbr += 48;
		write (1, &nbr, 1);
		count++;
	}
	return (count);
}

int	ft_putnbru(unsigned int n)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	nbr = n;
	if (nbr > 9)
	{
		count += ft_putnbr((nbr / 10));
		count += ft_putnbr((nbr % 10));
	}
	else
	{
		nbr += 48;
		write (1, &nbr, 1);
		count++;
	}
	return (count);
}
