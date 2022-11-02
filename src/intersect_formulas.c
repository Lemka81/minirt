#include "minirt.h"

double	sphIntersect(t_v3 ro, t_v3 rd, t_obj *o)
{
	t_v3	oc;
	double	b;
	double	h;
	
	oc = v3_sub(o->pos, ro);
	b = v3_dot(oc, rd);
	h = b * b - v3_dot(oc, oc) + o->par1 * o->par1;
	if(h <= 0)
		return (DBL_MAX);
	h = b - sqrt(h);
	if (h <= 0)
		return (DBL_MAX);
	o->insec = v3_sum(ro, v3_multd(rd, h));
	o->norm = v3_norm(v3_sub(o->insec, o->pos));
	return (h);
}

double	plnIntersect(t_v3 ro, t_v3 rd, t_obj *o)
{
	double	d;

	d = v3_dot(o->ang, rd);
	if (d == 0)
		return (DBL_MAX);
	d = -(v3_dot(ro, o->ang) - o->par1) / d;
	o->insec = v3_sum(ro, v3_multd(rd, d));
	o->norm = o->ang;
	return (d);
}

static double	cylIntersect1(t_v3 *ro, t_v3 *rd, t_cylinder *c, t_obj *o)
{
	o->insec = v3_sum(*ro, v3_multd(*rd, c->t));
	c->ba = v3_norm(v3_sub(o->pos, o->ang));
	o->norm = v3_multv(v3_norm(v3_multv(v3_sub(o->pos, o->insec), c->ba)), c->ba);
	return (c->t);
}

static double	cylIntersect2(t_v3 *ro, t_v3 *rd, t_cylinder *c, t_obj *o)
{
	o->insec = v3_sum(*ro, v3_multd(*rd, c->t));
	if (c->y > 0)
		o->norm = v3_norm(v3_sub(o->ang, o->pos));
	else
		o->norm = v3_sign(v3_norm(v3_sub(o->ang, o->pos)));
	return (c->t);
}

double	cylIntersect(t_v3 ro, t_v3 rd, t_obj *o)
{
	t_cylinder	c;

	c.ba = v3_sub(o->ang, o->pos);
	c.oc = v3_sub(ro, o->pos);
	c.baba = v3_dot(c.ba, c.ba);
	c.bard = v3_dot(c.ba, rd);
	c.baoc = v3_dot(c.ba, c.oc);
	c.k2 = c.baba - c.bard * c.bard;
	c.k1 = c.baba * v3_dot(c.oc, rd) - c.baoc * c.bard;
	c.k0 = c.baba * v3_dot(c.oc, c.oc) - c.baoc * c.baoc - o->par1 * o->par1 * c.baba;
	c.h = c.k1 * c.k1 - c.k2 * c.k0;
	if (c.h < 0)
		return (DBL_MAX);
	c.h = sqrt(c.h);
	c.t = (-c.k1 - c.h) / c.k2;
	c.y = c.baoc + c.t * c.bard;
	if (c.y > 0 && c.y < c.baba)
		return (cylIntersect1(&ro, &rd, &c, o));
	if (c.y < 0)
		c.t = -c.baoc / c.bard;
	else
		c.t = (c.baba - c.baoc) / c.bard;
	if (fabs(c.k1 + c.k2 * c.t) < c.h)
		return (cylIntersect2(&ro, &rd, &c, o));
	return (DBL_MAX);
}
