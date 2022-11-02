#include "minirt.h"

double	v3_len(t_v3 v1)
{
	double	length;

	length = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (length);
}

t_v3	v3_norm(t_v3 v1)
{
	v1 = v3_multd(v1, 1.0f / v3_len(v1));
	return (v1);
}

t_v3	v3_ref(t_v3 v, t_v3 n)
{
	return (v3_sub(v, v3_multd(n, (2 * v3_dot(n, v)))));
}

t_v3	v3_clamp(t_v3 c, double min, double max)
{
	if (c.x > max)
		c.x = max;
	if (c.y > max)
		c.y = max;
	if (c.z > max)
		c.z = max;
	if (c.x < min)
		c.x = min;
	if (c.y < min)
		c.y = min;
	if (c.z < min)
		c.z = min;
	return (c);
}

t_v3i	v3i(int x, int y, int z)
{
	t_v3i	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}
