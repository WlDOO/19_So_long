/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:59 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/21 18:17:04 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 0;
	fd = 0;
	if (ac != 2)
		return (ft_printf("error map"), 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("error map"), 0);
	while (av[1][i])
		i++;
	i--;
	if (av[1][i] != 'r')
		return (ft_printf("error map"), 0);
	i--;
	if (av[1][i] != 'e')
		return (ft_printf("error map"), 0);
	i--;
	if (av[1][i] != 'b')
		return (ft_printf("error map"), 0);
	i--;
	if (av[1][i] != '.')
		return (ft_printf("error map"), 0);
	so_long(fd);
}
