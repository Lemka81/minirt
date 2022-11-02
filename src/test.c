#include "minirt.h"

void    print_color(t_color c)
{
    printf("color: %d, %d, %d\n", c.r, c.b, c.g);
}

void    print_vec(t_v3 vec)
{
    printf("vec: %f, %f, %f\n", vec.x, vec.y, vec.z);
}