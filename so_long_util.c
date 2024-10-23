/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:25:25 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/22 18:28:31 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = (ft_strlen2(s1) + ft_strlen2(s2));
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (free(str), free(s1), NULL);
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}

size_t	ft_strlen2(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	str = (char *)s;
	while (str[i])
		i++;
	return (i);
}

t_vars	ft_xpm(t_vars vars)
{
	int	w;
	int	h;

	vars.map.moves = mlx_xpm_file_to_image(vars.mlx,
			"./image/player.xpm", &w, &h);
	vars.map.back = mlx_xpm_file_to_image(vars.mlx,
			"./image/back.xpm", &w, &h);
	vars.map.wall = mlx_xpm_file_to_image(vars.mlx,
			"./image/wall.xpm", &w, &h);
	vars.map.obj = mlx_xpm_file_to_image(vars.mlx,
			"./image/obj.xpm", &w, &h);
	vars.map.exit = mlx_xpm_file_to_image(vars.mlx,
			"./image/exit.xpm", &w, &h);
	if (vars.map.moves == 0 || vars.map.back == 0 || vars.map.wall == 0
		|| vars.map.obj == 0 || vars.map.exit == 0)
	{
		ft_printf("error image");
		exit(0);
	}
	return (vars);
}

int	ft_checkmove(t_vars vars)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	x = 0;
	while (vars.line[i])
	{
		if (vars.y == y && vars.x == x && vars.line[i] == 'E')
			return (2);
		else if (vars.y == y && vars.x == x && vars.line[i] != '1')
			return (1);
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

int	ft_check(char *line)
{
	int	i;
	int	x;
	int	y;

	y = 1;
	i = 0;
	x = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	while (line[x + i + y])
	{
		if (line[x + i + y] == '\n')
		{
			if (x != i)
				return (0);
			y += x + 1;
			x = 0;
		}
		x++;
	}
	if (line[x + i + y] == '\0')
		x--;
	if ((x) != i)
		return (0);
	return (1);
}
