/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:02:20 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 18:55:35 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

// libft func

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

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

// void	parse_ambient(t_store *st)
// {
// 	st->amb_str = ft_atof(st->split[1]);
// 	printf("amb_str = %f\n", st->amb_str);
// 	st->amb_light = split_rgb(st->split[2], st);
// 	if (st->amb_str > 1 || st->amb_str < 0)
// 		ft_error("Error\nInvalid scene\n");
// 	st->a_parsed = 1;
// }

void	parse_camera(t_store *st)
{
	if (count_split(st->split) != 4 || ft_strlen(st->split[2]) > 8)
		ft_error("Error\nInvalid scene\n");
	st->cam_pos = str_to_vec(st->split[1], st);
	st->cam_dir = str_to_vec(st->split[2], st);
	if (st->cam_dir.x > 1 || st->cam_dir.x < -1 \
		|| st->cam_dir.y > 1 || st->cam_dir.y < -1 \
		|| st->cam_dir.z > 1 || st->cam_dir.z < -1)
		ft_error("Error\nInvalid scene\n");
	if (st->cam_dir.x == 0 && st->cam_dir.y == 0 &&st->cam_dir.z == 0)
		ft_error("Error\nInvalid scene\n");
	st->vp.fov = ft_atoi(st->split[3]);
	if (st->vp.fov < 0 || st->vp.fov > 180)
		ft_error("Error\nInvalid scene\n");
	st->c_parsed = 1;
}

void	parse_light(t_rt *scene)
{
	if (count_split(st->split) != 4)
		ft_error("Error\nInvalid scene\n");
	st->lth_lo = str_to_vec(scene->split[1], st);
	st->lth_str = ft_atof(scene->split[2]);
	st->lth_color = split_rgb(scene->split[3], st);
	if (st->lth_str > 1 || st->lth_str < 0)
		ft_error("Error\nInvalid scene\n");
	st->l_parsed = 1;
}

void	parse_type_id(t_store *st)
{
	st->a_parsed = 0;
	st->c_parsed = 0;
	st->l_parsed = 0;
	
	// if ((ft_strcmp(st->split[0], "A") == 0) && st->a_parsed != 1)
	// 	parse_ambient(st);
	else if ((ft_strcmp(st->split[0], "C") == 0) && st->c_parsed != 1)
		parse_camera(st);
	else if ((ft_strcmp(st->split[0], "L") == 0) && st->l_parsed != 1)
		parse_light(st);
	// else if ((ft_strcmp(st->split[0], "pl") == 0))
	// 	parse_plane(st);
	// else if ((ft_strcmp(st->split[0], "sp") == 0))
	// 	parse_sphere(st);
	// else if ((ft_strcmp(st->split[0], "cy") == 0))
	// 	parse_cylindre(st);
	else
		ft_error("Error\nInvalid scene\n");
}

static void	check_file_extension(char *name)
{
	char	*format;

	format = ".rt";
	while (*name != '.' && *name != '\0')
		name++;
	if (*name == '\0')
		ft_error("Error\nInvalid scene\n");
	if (*name == '.')
	{
		if (ft_strncmp(name, format, 4) != 0)
			ft_error("Error\nInvalid scene\n");
	}
}

void parse(t_store *st,  char* rt_file)
{
	int fd;
	char *line;

	check_file_extension(rt_file);
	fd = open(rt_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		st->split = ft_split(line, " ");
		if (st->split[0])
			parse_type_id(st);
		free(line);
		get_next_line(fd);
	}
	free(line);
	close(fd);
}

// количество аргументов проверяем в main
