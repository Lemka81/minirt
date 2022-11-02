#include "minirt.h"

void force_quit(t_store *st)
{
	free_list(st->scobj);
	free(st->vp.mlx_image);
	free(st->vp.mlx_win);
	free(st->vp.mlx);
	printf("force quit executed!\n");
	close(1);
}

void temp_setup_vars(t_store *st)
{
	st->vp.width = 1280;
	st->vp.height = 720;
	st->vp.bits_per_pixel = 0;
	st->vp.mem_offset = 0;
	st->vp.fov = PI / 2;
	st->dt = 0;
}

void	pixel_put(t_store *st, int x, int y, unsigned int color)
{
	*(unsigned int *)((char *)st->vp.mlx_out_image + (y * st->vp.mem_offset + x *
					(st->vp.bits_per_pixel / 8))) = color;
}

void	init_set_zero(t_store *st)
{
	st->vp.mlx = NULL;
	st->vp.mlx_win = NULL;
	st->vp.mlx_image = NULL;
	st->vp.mlx_out_image = NULL;
	st->scobj = NULL;
}

void	create_circle_to_scene(t_store *st, t_v3 pos, t_color c, double r, double ref)
{
	t_obj	*c1;

	c1 = malloc(sizeof(t_obj));
	c1->type = CIRCLE;
	c1->pos = pos;
	c1->par1 = r;
	c1->color = c_to_v3(c);
	c1->ref = ref;
	if (push_back(&st->scobj, c1))
		force_quit(st);	
}

void	create_plain_to_scene(t_store *st, double w, t_color c, t_v3 ang, double ref)
{
	t_obj	*c1;

	c1 = malloc(sizeof(t_obj));
	c1->type = PLAIN;
	c1->par1 = w;
	c1->ang = v3_norm(ang);
	c1->color = c_to_v3(c);
	c1->ref = ref;
	if (push_back(&st->scobj, c1))
		force_quit(st);	
}

void	create_cylinder_to_scene(t_store *st, t_v3 p1, t_v3 p2, double r, t_color c, double ref)
{
	t_obj	*c1;

	c1 = malloc(sizeof(t_obj));
	c1->type = CYLINDER;
	c1->pos = p1;
	c1->ang = p2;
	c1->par1 = r;
	c1->color = c_to_v3(c);
	c1->ref = ref;
	if (push_back(&st->scobj, c1))
		force_quit(st);	
}

void	scene_setup(t_store *st)
{
	t_obj	*c1;
	t_color	wall_color = color(0, 30, 30, 70);


	const float	wall_mirror = 0.8;
	const float sphere_mirror = 0.1;
	// create_cylinder_to_scene(st, v3f(-1, 0, 4), v3f(1, 0, 4), 1, color(0, 100, 0, 0), 0);
	create_circle_to_scene(st, v3f(0, 0, 5), color(0, 100, 0, 0), 1, sphere_mirror);
	create_circle_to_scene(st, v3f(0, 1, 1), color(0, 0, 100, 0), 1, sphere_mirror);
	create_circle_to_scene(st, v3f(-1, -1, 1), color(0, 0, 0, 100), 1, sphere_mirror);
	create_plain_to_scene(st, -4, wall_color, v3f(0, 1, 0), wall_mirror);
	create_plain_to_scene(st, -4, wall_color, v3f(0, -1, 0), wall_mirror);
	create_plain_to_scene(st, -10, wall_color, v3f(0, 0, -1), wall_mirror);
	create_plain_to_scene(st, -7, wall_color, v3f(0, 0, 1), wall_mirror);
	create_plain_to_scene(st, -4, wall_color, v3f(1, 0, 0), wall_mirror);
	create_plain_to_scene(st, -4, wall_color, v3f(-1, 0, 0), wall_mirror);
	st->cam_pos = v3f(0, 0, 0);
	st->cam_dir = v3_norm(v3f(0, 1, 0));
	st->ref_count = 10;
	st->skyc = c_to_v3(color(0, 5, 5, 35));
	st->lo = v3f(3, 3, 2);
	st->amb_light = v3f(1, 1, 1);
	st->amb_str = 0;
	st->lth_color = v3f(1, 1, 1);
	st->lth_str = 1;
}

void	init(t_store *st)
{
	init_set_zero(st);
	temp_setup_vars(st);
	st->vp.mlx = mlx_init();
	st->vp.mlx_win = mlx_new_window(st->vp.mlx, st->vp.width, st->vp.height, "hello world!");
	st->vp.mlx_image = mlx_new_image(st->vp.mlx, st->vp.width, st->vp.height);
	st->vp.mlx_out_image = mlx_get_data_addr(st->vp.mlx_image, &st->vp.bits_per_pixel, &st->vp.mem_offset, &st->vp.endian);
	if (!st->vp.mlx_win || !st->vp.mlx_image || !st->vp.mlx_out_image)
		force_quit(st);
	scene_setup(st);
}

t_v3	rotate(t_v3 v, t_v3 a)
{
	t_v3	out;
	double	m[6];

	m[0] = a.z / sqrt(a.y * a.y + a.z * a.z);
	m[1] = a.y / sqrt(a.y * a.y + a.z * a.z);
	m[2] = a.x / sqrt(a.x * a.x + a.z * a.z);
	m[3] = a.z / sqrt(a.x * a.x + a.z * a.z);
	m[4] = a.x / sqrt(a.x * a.x + a.y * a.y);
	m[5] = a.y / sqrt(a.x * a.x + a.y * a.y);


	// out.x = a.x * a.x * v.x - a.x * a.y * v.y - a.z * v.z;
	// out.y = a.z * a.y * (1 - a.x) * v.x + a.z * (a.x + a.y * a.y) * v.y - a.x * a.y * v.z;
	// out.z = a.z * a.z * a.x * v.x * a.y * (a.x - a.z * a.z) * v.y + a.z * a.x * v.z;
	// out.x = a.x * v.x - a.z * v.y + a.y * v.z;
	// out.y = -a.y * v.x + a.x * v.y + a.z * v.z;
	// out.z = a.z * v.x + a.y * v.y - a.x * v.z;
	// out.x = a.x * v.x + a.z * v.y - a.y * v.z;
	// out.y = -a.z * v.x + a.y * v.y + a.x * v.z;
	// out.z = a.y * v.x - a.x * v.y + a.z * v.z;
	// out.x = a.x * v.x + a.z * v.y - a.y * v.z;
	// out.y = -a.z * v.x + a.y * v.y + a.z * v.z;
	// out.z = a.y * v.x - a.x * v.y + a.x * v.z;
	// out.x = a.z * v.x - a.x * v.y + a.y * v.z;
	// out.y = -a.y * v.x + a.z * v.y + a.x * v.z;
	// out.z = a.x * v.x + a.y * v.y - a.z * v.z;
	return (out);
}

int	cast_ray_by_pos(t_store *st, int x, int y, t_v3 step)
{
	t_v3	rd;
	t_v3	ro;

	rd.x = step.x * (x - st->vp.width / 2);
	rd.y = step.y * (y - st->vp.height / 2) * step.z;
	rd.z = 1;
	// rd = v3_multv(rd, st->cam_dir);
	rd = v3_norm(rd);
	// rd = v3_sign(rotate(rd, st->cam_dir));
	ro = st->cam_pos;
	// ro = v3_sum(rotate(v3_multd(v3_sub(rd, v3f(0, 0, 1)), 1), st->cam_dir), st->cam_pos);
	temp1 = x;
	temp2 = y;
	return (ray_cast(st, rd, ro, st->ref_count).i);
}

void	temp_draw_scene(t_store *st)
{
	t_v3	step;
	t_v3	rd;
	t_v3i	it;
	t_v3	ro;

	if (!st->scobj)
	{
		printf("scene is empty\n");
		return ;
	}
	st->vp.diff = tan(st->vp.fov / 2);
	step.x = 2.0 / st->vp.width * st->vp.diff;
	step.y = 2.0 / st->vp.height * st->vp.diff;
	step.z = (double)st->vp.height / st->vp.width;
	// st->amb_str = fabs(sin(st->dt * 0.1));
	// st->lo = v3f(cos(st->dt * 0.1) * 3, sin(st->dt * 0.1) * 3, cos(st->dt * 0.05) * 2);
	// st->scobj->data->pos = v3f(cos(st->dt * 0.1), sin(st->dt * 0.1), 4 + sin(st->dt * 0.1));
	// st->scobj->data->ang = v3f(-cos(st->dt * 0.1), -sin(st->dt * 0.1), 4 - sin(st->dt * 0.1));
	// st->ld = v3_norm(v3f(-1, sin(0.15 * st->dt), cos(0.15 * st->dt)));
	// st->vp.fov = (PI / 2) + sin(st->dt * 0.13) * (PI / 8) + (PI / 16);
	// st->ld = v3_norm(v3f(-1, 1, 1));
	// st->scobj->data->pos = v3f(-cos(st->dt * 0.15), -sin(st->dt * 0.15) * 1.5, 2);
	// st->scobj->next->data->pos = v3f(-cos(st->dt * 0.15), -sin(st->dt * 0.15) * 1.5, 10);
	// st->scobj->data->pos = v3f(sin(st->dt * 0.15) * 1.5, 0, 5);
	// st->scobj->next->data->pos = v3f(0, 0, 5);
	// st->cam_dir = v3_norm(v3f(0, st->dt * 0.11 , 1));
	// printf("st->cam_dir = ");
	// print_vec(st->cam_dir);
	it.x = 0;
	while (it.x < st->vp.width)
	{
		it.y = 0;
		while (it.y < st->vp.height)
		{
			
			pixel_put(st, it.x, it.y, cast_ray_by_pos(st, it.x, it.y, step));
			it.y++;
		}
		it.x++;
	}
}

int	update(void *store)
{
	t_store	*st;

	st = (t_store *)store;
	temp_draw_scene(st);
	mlx_put_image_to_window(st->vp.mlx, st->vp.mlx_win, st->vp.mlx_image, 0, 0);
	st->dt++;
	// st->amb_light = color_multv(st->amb_light, st->amb_str);
	printf("dt: %d\n", st->dt);
	return (0);
}

int	main(void) {
	t_store st;

	init(&st);
	update(&st);
	// mlx_mouse_hide();
	// t_v3	vec = {0, 0, 1};
	// print_vec(rotate(vec, v3f(1, 0, 0)));
	// print_vec(rotate(vec, v3f(0, 1, 0)));
	// print_vec(rotate(vec, v3_norm(v3f(0, 0, 1))));
	mlx_put_image_to_window(st.vp.mlx, st.vp.mlx_win, st.vp.mlx_image, 0, 0);
	mlx_loop_hook(st.vp.mlx, update, &st);
	mlx_loop(st.vp.mlx);
}


