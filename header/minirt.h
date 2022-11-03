#ifndef MINIRT_H
# define MINIRT_H
# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "math.h"
# include <limits.h>
# include <float.h>
# include <fcntl.h> 				//для парсера
# define PI	3.1415926535
# define CIRCLE 0
# define PLAIN 1
# define CYLINDER 2
// отладочные дефайны. Удалить перед сдачей!
#define WHITE v3f(1, 1, 1);
#define BLACK v3f(0, 0, 0);

int temp1, temp2;

typedef union u_color
{
	unsigned int	i;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	};
}	t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_v3i;

typedef struct s_obj
{
	int		type;
	t_v3	pos;
	t_v3	ang;
	t_v3	insec;
	t_v3	norm;
	t_v3	color;
	double	ref;
	double	par1;
	double	par2;
	double	par3;
}	t_obj;

typedef struct s_cylinder
{
	t_v3	ba;
	t_v3	oc;
	double	baba;
	double	bard;
	double	baoc;
	double	k2;
	double	k1;
	double	k0;
	double	h;
	double	t;
	double	y;
}	t_cylinder;

typedef struct s_list
{
	t_obj			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_viewport
{
	int		width;
	int		height;
	int		bits_per_pixel;
	int		endian;
	int		mem_offset;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_image;
	void	*mlx_out_image;
	double	fov; // fov
	double	diff;
}	t_viewport;

typedef struct	s_store
{
	char 		**split; 			//для парсера
	int 		a_parsed; 			//для парсера
	int 		c_parsed; 			//для парсера
	int 		l_parsed; 			//для парсера
	int			dt;
	int			ref_count;
	t_v3		lo; // light pos
	t_v3		cam_pos; // camera pos
	t_v3		cam_dir; // camera ang
	t_list		*scobj;
	t_v3		skyc;
	t_v3		amb_light; // ambient color
	double		amb_str; // cof ambient 
	t_v3		lth_color; // light color
	double		lth_str; // ligth str
	// double		shadow_coefficient;
	t_viewport	vp;
}	t_store;

typedef struct	s_raycast
{
	t_obj	*obj;
	double	dist;
	t_v3	intersect;
	t_v3	norm;
}	t_raycast;

typedef struct	s_phong
{
	t_v3	aml;
	t_v3	amo;
	t_v3	dfl;
	t_v3	dfo;
	t_v3	spl;
	t_v3	spo;
}	t_phong;

/* color utils */
t_color	color_multv(t_color c, double v);
t_color	color_blend(t_color c0, t_color c1, double ratio);
t_color	color(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
t_v3	c_to_v3(t_color c);
t_color	v3_to_c(t_v3 v);
t_v3	v3_clamp(t_v3 c, double min, double max);
t_v3	color_overload(t_v3 c);

/* Vector's operations */
t_v3	v3f(double x, double y, double z);
t_v3	v3_sign(t_v3 v1);
t_v3	v3_sum(t_v3 v1, t_v3 v2);
t_v3	v3_sumv(t_v3 v1, double v2);
t_v3	v3_sub(t_v3 v1, t_v3 v2);
t_v3	v3_subv(t_v3 v1, double v2);
t_v3	v3_multv(t_v3 v1, t_v3 v2);
t_v3	v3_multd(t_v3 v1, double v2);
t_v3	v3_mult(t_v3 v1, t_v3 v2);
double	v3_dot(t_v3 v1, t_v3 v2);
double	v3_len(t_v3 v1);
t_v3	v3_norm(t_v3 v1);
t_v3	v3_ref(t_v3 v, t_v3 n);

// Intersections with shepes
double	sphIntersect(t_v3 ro, t_v3 rd, t_obj *obj);
double	plnIntersect(t_v3 ro, t_v3 rd, t_obj *obj);
double	cylIntersect(t_v3 ro, t_v3 rd, t_obj *obj);

/*    list    */
t_list	*create_list(t_obj *data);
int		push_back(t_list **start, t_obj *data);
int		get_list_size(t_list *lst);
void	free_list(t_list *lst);

/*    ray_cast    */
t_color	ray_cast(t_store *st, t_v3 rd, t_v3 ro, int d);

/*    test    */
void    print_color(t_color c);
void	print_vec(t_v3 vec);

#endif