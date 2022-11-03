/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:01:15 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:29:00 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

void	parse_sphere(t_store *st)
{
	t_obj	*sphere;

	if (count_split(st->split) != 4)
		ft_error("Error\nInvalid scene\n");
	sphere = (t_obj *)malloc(sizeof(t_obj));
	sphere->pos = str_to_vec(st->split[1], st);
	sphere->diameter = ft_atof(st->split[2]);
	sphere->color = split_rgb(st->split[3], st);
	if (sphere->diameter < 0)
		ft_error("Error\nInvalid scene\n");
}

void	parse_plane(t_store *st)
{
	t_obj	*plane;

	if (count_split(st->split) != 4 || ft_strlen(st->split[2]) > 8)
		ft_error("Error\nInvalid scene\n");
	plane = (t_obj *)malloc(sizeof(t_obj));
	plane->pos = str_to_vec(st->split[1], st);
	plane->ang = str_to_vec(st->split[2], st);
	plane->color = split_rgb(st->split[3], st);
	check_normal(plane->ang);
}

void	parse_cylindre(t_store *st)
{
	t_obj	*cylind;

	if (count_split(st->split) != 6 || ft_strlen(st->split[2]) > 8)
		ft_error("Error\nInvalid scene\n");
	cylind = (t_obj *)malloc(sizeof(t_obj));
	cylind->pos = str_to_vec(st->split[1], st);
	cylind->ang = str_to_vec(st->split[2], st);
	cylind->diameter = ft_atof(st->split[3]);		//переименовать или добавить в структуру
	cylind->height = ft_atof(st->split[4]);			//переименовать или добавить в структуру
	cylind->color = split_rgb(st->split[5], st);
	check_normal(cylind->ang);
}
