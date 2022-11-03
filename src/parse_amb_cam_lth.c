/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_cam_lth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:05:52 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:30:15 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

void	parse_ambient(t_store *st)
{
	st->amb_str = ft_atof(st->split[1]);
	st->amb_light = split_rgb(st->split[2], st);
	if (st->amb_str > 1 || st->amb_str < 0)
		ft_error("Error\nInvalid scene\n");
	st->a_parsed = 1;
}

void	parse_camera(t_store *st)
{
	if (count_split(st->split) != 4 || ft_strlen(st->split[2]) > 8)
		ft_error("Error\nInvalid scene\n");
	st->cam_pos = str_to_vec(st->split[1], st);
	st->cam_dir = str_to_vec(st->split[2], st);
	check_normal(st->cam_dir);
	st->vp.fov = PI / 180 * ft_atoi(st->split[3]);
	if (st->vp.fov < 0 || st->vp.fov > 180)
		ft_error("Error\nInvalid scene\n");
	st->c_parsed = 1;
}

void	parse_light(t_store *st)
{
	if (count_split(st->split) != 4)
		ft_error("Error\nInvalid scene\n");
	st->lo = str_to_vec(st->split[1], st);
	st->lth_str = ft_atof(st->split[2]);
	st->lth_color = split_rgb(st->split[3], st);
	if (st->lth_str > 1 || st->lth_str < 0)
		ft_error("Error\nInvalid scene\n");
	st->l_parsed = 1;
}
