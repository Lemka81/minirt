#include "minirt.h"

double	find_intersect(t_store *st, t_v3 rd, t_v3 ro, t_obj **obj)
{
	t_list	*cur;
	double	curmin;
	double	dist;

	cur = st->scobj;
	dist = DBL_MAX;
	while (cur)
	{
		if (cur->data->type == CIRCLE)
			curmin = sphIntersect(ro, rd, cur->data);
		else if (cur->data->type == PLAIN)
			curmin = plnIntersect(ro, rd, cur->data);
		else if (cur->data->type == CYLINDER)
			curmin = cylIntersect(ro, rd, cur->data);
		if (curmin < dist && curmin > 0.00000001)
		{
			*obj = cur->data;
			dist = curmin;
		}
		cur = cur->next;
	}
	return (dist);
}

// t_color	find_additional_info(t_store *st, t_raycast	*rc, t_v3 rd, t_v3 ro)
// {
// 	t_raycast	rcl;
// 	double		ld;
// 	double		light_spot;

// 	rcl.norm = v3_sub(st->lo, rc->obj->insec);
// 	rcl.dist = v3_len(rcl.norm);
// 	rcl.norm = v3_norm(rcl.norm);
// 	ld = v3_dot(rcl.norm, rc->norm);
// 	ld = 0.5 * (ld + 1);
// 	if (ld < 0.5 || rcl.dist > find_intersect(st, rcl.norm, rc->obj->insec, &rcl.obj))
// 	{
// 		ld *= st->shadow_coefficient;
// 		ld = st->amb_str * (ld - 1) + 1;
// 		return (color_blend(rc->obj->color, st->amb_light, ld));
// 	}
// 	light_spot = (ld - 1) * 10 + 1;
// 	ld *= 1 / (rcl.dist + 10) * 10;
// 	if (st->is_ligth_spot && light_spot >= 0)
// 		return (color_blend(color(0, 255, 255, 255), color_blend(
// 				rc->obj->color, st->amb_light, ld),
// 					pow(light_spot, 100)));
// 	ld = st->amb_str * (ld - 1) + 1;
// 	return (color_blend(rc->obj->color, st->amb_light, ld));
// }



t_color	calculate_color(t_store *st, t_raycast	*rc, t_v3 rd, t_v3 ro)
{
	t_raycast	rcl;
	t_v3		color;
	t_v3		temp;

	rcl.norm = v3_sub(rc->obj->insec, st->lo);
	rcl.norm = v3_norm(rcl.norm);
	rcl.intersect = rd;
	rcl.dist = v3_dot(rcl.norm, v3_sign(rc->obj->norm));
	color = v3_mult(rc->obj->color, st->amb_light);
	color = v3_sum(v3_clamp(v3_multd(v3_mult(rc->obj->color, st->lth_color),
				rcl.dist), st->amb_str - 1, st->lth_str), color);
	temp = v3_sum(rcl.norm, rcl.intersect);
	temp = v3_multd(st->lth_color, pow(v3_dot(v3_sign(rc->obj->norm), v3_norm(
		v3_multd(temp, 1.0 / v3_len(temp)))), 100));
	color = v3_sum(v3_multd(temp, st->lth_str * 0.5), color);
	color = v3_clamp(color, 0, 1);
	if (v3_len(v3_sub(rc->obj->insec, st->lo)) > find_intersect(st,
		v3_sign(rcl.norm), rc->obj->insec, &rcl.obj))
		color = v3_multd(color, 0.5);
	return (v3_to_c(color));
}

t_color	ray_cast(t_store *st, t_v3 rd, t_v3 ro, int d)
{
	t_raycast	rc;
	t_color		out;

	rc.obj = st->scobj->data;
	rc.dist = find_intersect(st, rd, ro, &rc.obj);
	if (rc.dist == DBL_MAX)
	{
		return (v3_to_c(st->skyc));
	}
	out = calculate_color(st, &rc, rd, ro);
	rc.norm = v3_ref(rd, rc.obj->norm);
	if (d > 0 && rc.obj->ref != 0)
		out = color_blend(ray_cast(st, rc.norm, rc.obj->insec, d - 1), out, rc.obj->ref);
	return (out);
}
