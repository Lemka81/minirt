/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:42:13 by ohaggard          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:13 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/minirt.h"

t_color	color_blend(t_color c0, t_color c1, double ratio)
{
	t_color	out;

	out.t = 0;
	out.r = (int)(c0.r * ratio + c1.r * (1.0 - ratio));
	out.g = (int)(c0.g * ratio + c1.g * (1.0 - ratio));
	out.b = (int)(c0.b * ratio + c1.b * (1.0 - ratio));
	return (out);
}

t_color	color_multv(t_color c, double v)
{
	t_color	out;

	out.t = 0;
	out.r = v * c.r;
	out.g = v * c.g;
	out.b = v * c.b;
	return (out);
}

t_color	color(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b)
{
	t_color	c;

	c.t = t;
	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_v3	c_to_v3(t_color c)
{
	t_v3	out;

	out.x = (double)c.r / 255;
	out.y = (double)c.g / 255;
	out.z = (double)c.b / 255;
	return (out);
}

t_color	v3_to_c(t_v3 v)
{
	t_color	out;

	out.t = 0;
	out.r = v.x * 255;
	out.g = v.y * 255;
	out.b = v.z * 255;
	return (out);
}
