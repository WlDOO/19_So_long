/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:23:21 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/23 11:43:59 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	while (line[i])
	{
		if (line[i] == '\n' && (line[i + 1] != '1' || line[i - 1] != '1'))
			return (0);
		i++;
	}
	if (line[i] == '\0')
		i--;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	ft_checkchar(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C'
			|| line[i] == 'E' || line[i] == 'P' || line[i] == '\n')
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

void	ft_look_sec(t_vars *vars)
{
	vars->maps = ft_split(vars->line, '\n');
	vars->size = check_map(vars->line);
	if (vars->size.ex != 1 || vars->size.p != 1 || vars->size.obj < 1
		|| ft_check_wall(vars->line) == 0 || ft_check(vars->line) == 0
		|| ft_checkchar(vars->line) == 0)
		return (ft_printf("error map\n"), exit(0));
	ft_start(vars->maps, &*vars);
	if (ft_backtrack(vars->maps, vars->start.x,
			vars->start.y, &vars->start) == 0)
		return (ft_printf("not finish"), exit(0));
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
