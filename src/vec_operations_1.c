#include "minirt.h"

t_v3	v3_subv(t_v3 v1, double v2)
{
	v1.x = v1.x - v2;
	v1.y = v1.y - v2;
	v1.z = v1.z - v2;
	return (v1);
}

t_v3	v3_multv(t_v3 v1, t_v3 v2)
{
	t_v3	out;

	out.x = v1.y * v2.z - v1.z * v2.y;
	out.y = v1.z * v2.x - v1.x * v2.z;
	out.z = v1.x * v2.y - v1.y * v2.x;
	return (out);
}

t_v3	v3_multd(t_v3 v1, double v2)
{
	v1.x = v1.x * v2;
	v1.y = v1.y * v2;
	v1.z = v1.z * v2;
	return (v1);
}

t_v3	v3_mult(t_v3 v1, t_v3 v2)
{
	v1.x = v1.x * v2.x;
	v1.y = v1.y * v2.y;
	v1.z = v1.z * v2.z;
	return (v1);
}

double	v3_dot(t_v3 v1, t_v3 v2)
{
	double	out;

	out = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (out);
}
