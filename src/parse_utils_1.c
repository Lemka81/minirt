/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:52:02 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 20:52:55 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

int	count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

t_v3	str_to_vec(char *str, t_store *st)
{
	char		**split;
	t_v3	vector;
	double		x;
	double		y;
	double		z;

	split = ft_split(str, ',');
	if (count_split(split) != 3 || ft_str_c_count(str, ',') != 2)
	{
		split_clear(split);
		ft_error("Error\nInvalid scene\n");
	}
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	vector = v3f(x, y, z);
	split_clear(split);
	return (vector);
}

void	check_normal(t_v3 vector)
{
	if (vector.x > 1 || vector.x < -1 \
		|| vector.y > 1 || vector.y < -1 \
		|| vector.z > 1 || vector.z < -1)
		ft_error("Error\nInvalid scene\n");
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		ft_error("Error\nInvalid scene\n");
}
