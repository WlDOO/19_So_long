/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:39:17 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/21 15:35:57 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_word(const char *str, char sep)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
			w++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (w);
}

int	ft_count_size(const char *str, char sep, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (c == 0)
		{
			while (str[i] && str[i] != sep)
			{
				c++;
				i++;
			}
			return (c);
		}
		while (str[i] && str[i] != sep)
			i++;
		c--;
	}
	return (0);
}

static char	*ft_write_word(const char *str, char sep, int c, char *str1)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (c == 0)
		{
			while (str[i] && str[i] != sep)
			{
				str1[j] = str[i];
				j++;
				i++;
			}
			str1[j] = '\0';
			return (str1);
		}
		while (str[i] && str[i] != sep)
			i++;
		c--;
	}
	return (0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		a;

	if (!s)
		return (NULL);
	a = (ft_count_word(s, c) + 1);
	str = malloc(sizeof(char *) * a);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_count_word(s, c))
	{
		str[i] = malloc((ft_count_size(s, c, i) + 1) * sizeof(char));
		if (!str[i])
			return (free_tab(str), NULL);
		str[i] = ft_write_word(s, c, i, str[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
