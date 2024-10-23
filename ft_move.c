/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:24:13 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/21 17:08:26 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_vars *vars)
{
	vars->x2 = vars->x;
	vars->y2 = vars->y;
	get_map(*vars);
	if (keycode == 53)
		return (mlx_destroy_window(vars->mlx, vars->win), exit(0), 0);
	else
		key_handler2(keycode, vars);
	if (ft_checkmove(*vars) == 2 && vars->size.obj == 0)
		exit(0);
	if (ft_checkobj(*vars) != 0)
	{
		vars->line[ft_checkobj(*vars)] = '0';
		vars->size.obj--;
		get_map(*vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.moves,
		vars->x, vars->y);
	if (vars->x2 != vars->x || vars->y2 != vars->y)
		ft_printf("moves : %d\n", ++vars->i);
	return (0);
}

int	key_handler2(int keycode, t_vars *vars)
{
	if (keycode == 0 || keycode == 123)
	{
		vars->x -= 64;
		if (ft_checkmove(*vars) == 0)
			vars->x += 64;
	}
	if (keycode == 1 || keycode == 125)
	{
		vars->y += 64;
		if (ft_checkmove(*vars) == 0)
			vars->y -= 64;
	}
	else if (keycode == 13 || keycode == 126)
	{
		vars->y -= 64;
		if (ft_checkmove(*vars) == 0)
			vars->y += 64;
	}
	else if (keycode == 2 || keycode == 124)
	{
		vars->x += 64;
		if (ft_checkmove(*vars) == 0)
			vars->x -= 64;
	}
	return (0);
}

int	ft_checkobj(t_vars vars)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	x = 0;
	while (vars.line[i])
	{
		if (vars.y == y && vars.x == x && vars.line[i] == 'C')
			return (i);
		x += 64;
		if (vars.line[i] == '\n')
		{
			x = 0;
			y += 64;
		}
		i++;
	}
	return (0);
}
