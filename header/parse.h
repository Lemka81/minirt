/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:11:05 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 21:27:06 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../header/minirt.h"

void    parse(t_store *st,  char* rt_file);
void	check_file_extension(char *name);
void	parse_type_id(t_store *st);

void	parse_ambient(t_store *st);
void	parse_camera(t_store *st);
void	parse_light(t_store *st);

t_v3	split_rgb(char *rgb, t_store *st);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(char *msg);
double	ft_atof(char *str);
int	    count_split(char **split);
t_v3	str_to_vec(char *str, t_store *st);
void	check_normal(t_v3 vector);
int	    ft_str_c_count(char *str, char c);
char	**split_clear(char **split);


#endif