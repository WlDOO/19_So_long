/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:50:26 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/22 19:07:31 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	get_map(t_vars vars)
{
	int		i;

	vars.pos.x = 0;
	vars.pos.y = 0;
	i = -1;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.map.back, 0, 0);
	while (vars.line[++i])
	{
		if (vars.line[i] == '1')
			mlx_put_image_to_window(vars.mlx, vars.win, vars.map.wall,
				vars.pos.x, vars.pos.y);
		else if (vars.line[i] == 'E')
			mlx_put_image_to_window(vars.mlx, vars.win, vars.map.exit,
				vars.pos.x, vars.pos.y);
		else if (vars.line[i] == 'C')
			mlx_put_image_to_window(vars.mlx, vars.win, vars.map.obj,
				vars.pos.x, vars.pos.y);
		vars.pos.x += 64;
		if (vars.line[i] == '\n')
		{
			vars.pos.x = 0;
			vars.pos.y += 64;
		}
	}
	return (vars);
}

char	*recup_map(int fd)
{
	char	*line;
	char	*buffer;
	int		bs;

	bs = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (line);
	while (bs >= 0)
	{
		bs = read(fd, buffer, 1);
		if (bs == -1)
			return (free(buffer), free(line), NULL);
		if (bs == 0)
			break ;
		buffer[bs] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	line = ft_strjoin(line, buffer);
	close(fd);
	return (free(buffer), line);
}

t_data	check_map(char *line)
{
	t_data	size;
	int		i;

	i = 0;
	size.x = 0;
	size.y = 1;
	size.obj = 0;
	size.ex = 0;
	size.p = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			size.y++;
		if (line[i] == 'C')
			size.obj++;
		if (line[i] == 'E')
			size.ex++;
		if (line[i] == 'P')
			size.p++;
		i++;
	}
	while (line[size.x] && line[size.x] != '\n')
		size.x++;
	return (size);
}

t_vars	player_pos(char *line, t_vars vars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			return (vars);
		else if (line[i] == '\n')
		{
			vars.x = 0;
			vars.y += 64;
			i++;
		}
		else
		{
			i++;
			vars.x += 64;
		}
	}
	return (vars);
}

void	so_long(int fd)
{
	t_vars	vars;

	vars.i = 0;
	vars.x = 0;
	vars.y = 0;
	vars.line = NULL;
	vars.line = recup_map(fd);
	ft_look_sec(&vars);
	vars = player_pos(vars.line, vars);
	if (vars.size.x > 40 || vars.size.y > 22)
		return (ft_printf("error size\n"), free(vars.line), free(vars.maps));
	vars = ft_xpm(vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(0);
	vars.win = mlx_new_window(vars.mlx, (vars.size.x * 64),
			(vars.size.y * 64), "so_long");
	if (!vars.win)
		exit(0);
	get_map(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.map.moves, vars.x, vars.y);
	mlx_key_hook(vars.win, key_handler, &vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
