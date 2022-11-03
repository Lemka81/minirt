/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:02:20 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:23:02 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"
#include "../header/parse.h"

void	parse_type_id(t_store *st)
{
	st->a_parsed = 0;
	st->c_parsed = 0;
	st->l_parsed = 0;
	
	if ((ft_strcmp(st->split[0], "A") == 0) && st->a_parsed != 1)
		parse_ambient(st);
	else if ((ft_strcmp(st->split[0], "C") == 0) && st->c_parsed != 1)
		parse_camera(st);
	else if ((ft_strcmp(st->split[0], "L") == 0) && st->l_parsed != 1)
		parse_light(st);
	else if ((ft_strcmp(st->split[0], "sp") == 0))
		parse_sphere(st);
	else if ((ft_strcmp(st->split[0], "pl") == 0))
		parse_plane(st);
	else if ((ft_strcmp(st->split[0], "cy") == 0))
		parse_cylindre(st);
	else
		ft_error("Error\nInvalid scene\n");
}

void	check_file_extension(char *name)
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
