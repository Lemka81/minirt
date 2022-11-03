/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:48:00 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:22:47 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

int	ft_str_c_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}

char	**split_clear(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return (split);
}

static int	check_color(char **rgb)
{
	double	r;
	double	g;
	double	b;

	if (rgb[0][0] == '-' || rgb[1][0] == '-' || rgb[2][0] == '-')
		return (1);
	r = ft_atof(rgb[0]);
	g = ft_atof(rgb[1]);
	b = ft_atof(rgb[2]);
	if (r < 0 || r > 255)
		return (1);
	else if (b < 0 || b > 255)
		return (1);
	else if (g < 0 || g > 255)
		return (1);
	return (0);
}

t_v3	split_rgb(char *rgb, t_store *st)
{
	t_v3	col;
	char	**split;

	split = ft_split(rgb, ',');
	if (count_split(split) != 3 || ft_str_c_count(rgb, ',') != 2)
	{
		split_clear(split);
		ft_error("Error\nInvalid scene\n");
	}
	if (check_color(split))
		ft_error("Error\nInvalid scene\n");
	col.x = ft_atof(split[0]) / 255.0;
	col.y = ft_atof(split[1]) / 255.0;
	col.z = ft_atof(split[2]) / 255.0;
	split_clear(split);
	if (col.x < 0 || col.x > 1 || col.y < 0 || col.y > 1 || col.z < 0 || col.z > 1)
		ft_error("Error\nInvalid scene\n");
	return (col);
}
