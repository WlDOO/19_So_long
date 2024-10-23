/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:04 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/21 15:32:21 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_start(char **maps, t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars->start.exit = 1;
	vars->start.obj = vars->size.obj;
	while (maps[y] != NULL)
	{
		x = 0;
		while (maps[y][x])
		{
			x++;
			if (maps[y][x] == 'P')
			{
				vars->start.x = x;
				vars->start.y = y;
			}
		}
		y++;
	}
}

int	ft_backtrack(char **maps, int x, int y, t_start *str)
{
	int		i;

	i = 0;
	if (maps[y][x] == '1' || maps[y][x] == 'y')
		return (0);
	if (maps[y][x] == 'C' || maps[y][x] == 'E' || maps[y][x] == '0'
		|| maps[y][x] == 'P')
	{
		if (maps[y][x] == 'C')
			str->obj--;
		if (maps[y][x] == 'E')
			str->exit--;
		maps[y][x] = 'y';
	}
	ft_backtrack(maps, (x + 1), y, str);
	ft_backtrack(maps, (x - 1), y, str);
	ft_backtrack(maps, x, (y + 1), str);
	ft_backtrack(maps, x, (y - 1), str);
	if (str->obj == 0 && str->exit == 0)
		return (1);
	return (0);
}
