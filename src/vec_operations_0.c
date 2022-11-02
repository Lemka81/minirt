#include "minirt.h"

t_v3	v3f(double x, double y, double z)
{
	t_v3	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_v3	v3_sign(t_v3 v1)
{
	v1.x = -v1.x;
	v1.y = -v1.y;
	v1.z = -v1.z;
	return (v1);
}

t_v3	v3_sum(t_v3 v1, t_v3 v2)
{
	v1.x = v1.x + v2.x;
	v1.y = v1.y + v2.y;
	v1.z = v1.z + v2.z;
	return (v1);
}

t_v3	v3_sumv(t_v3 v1, double v2)
{
	v1.x = v1.x + v2;
	v1.y = v1.y + v2;
	v1.z = v1.z + v2;
	return (v1);
}

t_v3	v3_sub(t_v3 v1, t_v3 v2)
{
	v1.x = v1.x - v2.x;
	v1.y = v1.y - v2.y;
	v1.z = v1.z - v2.z;
	return (v1);
}
