/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:29:59 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/22 17:49:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_start
{
	int	y;
	int	x;
	int	obj;
	int	exit;
}				t_start;

typedef struct s_data
{
	int	y;
	int	x;
	int	obj;
	int	ex;
	int	p;
}				t_data;

typedef struct s_pos
{
	int	y;
	int	x;
}				t_pos;

typedef struct s_env
{
	void	*back;
	void	*obj;
	void	*wall;
	void	*moves;
	void	*exit;
}				t_env;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	char	*line;
	char	**maps;
	int		i;
	int		x2;
	int		y2;
	t_env	map;
	t_data	size;
	t_start	start;
	t_pos	pos;
}				t_vars;

t_data	check_map(char *line);
void	ft_look_sec(t_vars *vars);
int		ft_exit(void);
int		ft_checkchar(char *line);
void	ft_start(char **maps, t_vars *vars);
int		ft_backtrack(char **maps, int x, int y, t_start *str);
char	**ft_split(char const *s, char c);
int		ft_check_wall(char *line);
int		ft_checkobj(t_vars obj);
int		ft_check(char *line);;
int		ft_checkmove(t_vars vars);
t_vars	get_map(t_vars vars);
t_vars	ft_xpm(t_vars vars);
int		key_handler(int keycode, t_vars *vars);
int		key_handler2(int keycode, t_vars *vars);
size_t	ft_strlen2(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*recup_map(int fd);
void	so_long(int fd);

#endif