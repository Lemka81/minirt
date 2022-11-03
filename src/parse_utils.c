/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:19:37 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 18:05:09 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

// atoi double

size_t	ft_intlen(int n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

double	ft_atof(char *str)
{
	double	atof;
	int		atoi;
	int		i;
	int		fac;

	fac = 1;
	atof = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		fac = -1;
	atoi = ft_atoi(str);
	i = ft_intlen(atoi);
	if (fac == -1)
		i++;
	if (str[i++] != '.')
		return (atoi);
	while (str[i] >= '0' && str[i] <= '9')
	{
		fac *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	return (atoi + (atof / fac));
}

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

void	ft_strdel(char **as)
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

int	check_color(char **rgb)
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

t_color	split_rgb(char *rgb, t_store *st)
{
	t_color	col;
	char	**split;

	split = ft_split(rgb, ',');
	if (count_split(split) != 3 || ft_str_c_count(rgb, ',') != 2)
	{
		split_clear(split);
		ft_error("Error\nInvalid scene\n");
	}
	if (check_color(split))
		ft_error("Error\nInvalid scene\n");
	col.r = ft_atof(split[0]) / 255.0;
	col.g = ft_atof(split[1]) / 255.0;
	col.b = ft_atof(split[2]) / 255.0;
	split_clear(split);
	if (col.r < 0 || col.r > 1 || col.g < 0 || col.g > 1 || col.b < 0 || col.b > 1)
		ft_error("Error\nInvalid scene\n");
	return (col);
}
