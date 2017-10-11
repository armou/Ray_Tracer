
# define WIDTH 1200
# define HEIGHT 800
# define FOV 45
# define PI180  0.01745329251


typedef	struct	s_color
{
	double	r;
	double	g;
	double	b;
	double	a;
}				t_color;

typedef struct  s_record
{
    float4      hitpoint;
    float4      normale;
    float       t;
	float		res_t[4];
    int         hitobject;
    int         semit;
	int			type;
	t_color 	color;
}                t_record;

typedef struct  s_opencl
{
	int			bpp;
	int			sizeline;
	int			depth;
	int			moove;
	int			al;

	int			size_t1;
	int			size_t2;
	int			size_t3;
	int			size_t4;
	int			size_t5;

	int			w1;
	int			w2;
	int			w3;
	int			w4;
	int			w5;

	int			h1;
	int			h2;
	int			h3;
	int			h4;
	int			h5;

	int			bpp1;
	int			bpp2;
	int			bpp3;
	int			bpp4;
	int			bpp5;
	
	char		*data1;
	char		*data2;
	char		*data3;
	char		*data4;
	char		*data5;

	int			permutation[256];
	float		density;
	int			filter;
	int			motion_b;
	float		ambiante;
}				t_opencl;


typedef struct	s_pos
{
	double		x;
	double		y;
	double		z;
}				t_pos;

typedef struct  s_camera
{
	t_pos	origin;
	t_pos	dir;
	t_pos	rot;
}				t_camera;

typedef struct  s_object
{
	int					number;
	int					type;
	t_pos				origin;
	t_pos				rot;
	t_pos				trois;
	double				size;
	double				b_size;
	double				reflection;
	t_color				color;
	int					texture;
	
	struct s_object 	*next;

}				t_object;

typedef struct	s_n_cam
{
	float4		dir;
	float4		ori;
	float4		rot;
}				t_n_cam;

// ----------------------------- POUR LE TORUS ----------------------------------------


# define R sol.ret1
# define R2 sol.ret2
# define R3 sol.ret3
# define R4 sol->ret4
# define R5 sol.ret5
# define R6 sol->ret6
# define R7 sol.ret7
# define TA sol->a
# define AL sol->alpha

typedef struct	s_5pow
{
	double		q3;
	double		q2;
	double		q1;
	double		q0;
	double		q4;
}				t_5pow;

typedef struct	s_4pow
{
	double		q3;
	double		q2;
	double		q1;
	double		q0;
}				t_4pow;

typedef struct	s_3pow
{
	double		q2;
	double		q1;
	double		q0;
}				t_3pow;

typedef struct	s_cub_sol
{
	t_3pow		a;
	double		q;
	double		r;
	double		d;
}				t_cub_sol;

typedef struct	s_quartic_sol
{
	t_5pow		r;
	int			alpha;
	int			beta;
	t_4pow		a;
	t_4pow		new_a;
	t_4pow		x;
	int			nbr;
	int			useless;
	double		ret1;
	double		ret2;
	double		ret3;
	double		ret4;
	double		ret5;
	double		ret6;
	double		ret7;
	double		f1;
	double		f2;
}				t_quartic_sol;

int			solveur_part_2(t_quartic_sol *sol);
int			solveur_part_1(t_quartic_sol *sol);
void		find_new_sol(t_5pow d, t_4pow *a, t_4pow *new_a);
void		solve_2(t_cub_sol sol, t_4pow *x, int *nr);
void		solve_1(t_cub_sol sol, t_4pow *x, int *nr);
void		cubic_equation(t_4pow c, t_4pow *x, int *nr);
int			quartic_solver(double *ret, t_5pow d);
int			return_quartic(double *ret, t_quartic_sol sol);
float		check_ret(double *ret);

int			solveur_part_22(t_quartic_sol *sol);
int			solveur_part_12(t_quartic_sol *sol);
void		find_new_sol2(t_5pow d, t_4pow *a, t_4pow *new_a);
void		solve_22(t_cub_sol sol, t_4pow *x, int *nr);
void		solve_12(t_cub_sol sol, t_4pow *x, int *nr);
void		cubic_equation2(t_4pow c, t_4pow *x, int *nr);
int			quartic_solver2(double *ret, t_5pow d);
int			return_quartic2(double *ret, t_quartic_sol sol);
float		check_ret2(double *ret);

// ----------------------------- FIN POUR LE TORUS ----------------------------------------


void		ft_calc_ray(t_n_cam *camera, int const x, int const y, int al_tmp);
int			trace(t_n_cam *camera, global t_object *obj, int nb, int *hitobject, float *tnear, int light_or_not, t_record  *rec);
int			ray_dist(float discr, float b, float *t, float a, t_record  *rec);
int			sphere_hit(t_n_cam *cam, t_object sp, float *t, t_record  *rec, float t_res);
int			plan_hit(t_n_cam *cam, t_object pl, float *t, t_record *rec, float t_res);
int			cone_hit(t_n_cam *cam, t_object co, float *t, t_record *rec, float t_res);
int			cylinder_hit(t_n_cam *cam, t_object cyl, float *t, t_record *rec, float t_res);
int			torus_hit(t_n_cam *cam, t_object tor, float *t, t_record *rec, float t_res);
int 		triangle_hit(t_n_cam *cam, t_object tle, float *t, t_record  *rec, float t_res);
void		fsdl_draw_pt(__global unsigned char *data, __constant t_opencl *opencl, int clr, int x, int y);
int 		get_color_bis(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void   		get_rgb_from_int(int col, t_color *color);
float4  	get_normale(t_n_cam *camera, global t_object *tab, int i, float4 hitpoint, float t);
int			sort_absfloat_tab(float *tab, int len);
int			alter_hit(t_n_cam *cam, t_object alter, float *t, t_record *rec, float t_res);





/*+--------------------------FONCTION POUR LIGHT ET TEXTURE--------------------------*/
t_color    	load_tex(__constant  t_opencl *opencl, int hitobject, global t_object *tab, t_n_cam *camera, float t);
void    	texture_mapping(int *i, int *j, global t_object *tab, int hitobject, void *surf, t_n_cam *cam, int w, int h, float t);
t_color     proc_tex(__constant  t_opencl *opencl, int hitobject, __global t_object *tab, t_n_cam *camera, t_record *rec);
int         checker_tex(float4 hitpoint);
t_color     wood(float p, float4 hitpoint, t_color obj_col, __constant  t_opencl *opencl);
float       noise(float4 vector, __constant  t_opencl *opencl);
t_color     marbre(float p, float4 hitpoint, t_color obj_col, __constant  t_opencl *opencl);
void 		perlin (int *p, __constant  t_opencl *opencl);
float       fade(float t);
float       lerp(float t, float a, float b);
float       grad(int hash, float x, float y, float z);
void		normal_water(double d, t_record *rec, float4 inter, float4 dir, int texture, __constant  t_opencl *opencl);
void        modif_normale(double density, t_record *rec, float4 hitpoint, __constant  t_opencl *opencl);
void		filter_color(__constant t_opencl *opencl, t_color *final_color);
t_color 	color_light(__constant  t_opencl *opencl, int hitobject, __global t_object *tab, int  nb, t_n_cam *camera, float t, t_record rec[10]);
t_color 	apply_light(__constant t_opencl *opencl, int hitobject, __global t_object *tab, int nb, t_record rec, t_n_cam *camera);
t_color 	fill_final_color(t_color object_color, t_color material_color, __global t_object *tab, t_record *rec);
float4 		reflect(float4 i, float4 n);
t_color 	reflect_ray(__constant 	t_opencl *opencl, __global t_object *tab, int nb, t_n_cam *camera, int hitobject, t_record *rec);
void	 	transparent_text(__constant t_opencl *opencl, int hitobject, __global t_object *tab, t_n_cam *camera, t_record *rec, int nb);
t_color 	get_texture(__constant t_opencl *opencl, int hitobject, __global t_object *tab, t_n_cam *camera, t_record *rec);
void 		assign_new_ray(__global t_object *tab, t_n_cam *ray, t_n_cam *source, int hitobject, float t, t_record rec, int r);


/*+---------------------------------------------------------------------------------*/


float		carre(float c);
float		cube(float c);
void		rotate_x(t_n_cam *camera);
void		rotate_y(t_n_cam *camera);
void		rotate_z(t_n_cam *camera);
double		carre_d(double c);
double		cube_d(double c);



/*----------------------FONCTION CARRE ET CUBE PARCE AUE OPENCL BUG--------------------*/
float		carre(float c)
{
	return ((float)(c * c));
}

float		cube(float c)
{
	return ((float)(c * c * c));
}

double		carre_d(double c)
{
	return ((double)(c * c));
}

double		cube_d(double c)
{
	return ((double)(c * c * c));
}

/*-----------------------FONCTION DE ROTATE POUR NE PAS AVOIR LES OBJETS DEFORMER--------------------*/

void		rotate_x(t_n_cam *camera)
{
	float        y_tmp;
	float        z_tmp;
	float		  angle;

	angle = (camera->rot.x * ((M_PI * 0.5f * FOV) / 180.0f));
	
	y_tmp = camera->dir.y;
	z_tmp = camera->dir.z;
	camera->dir.y = y_tmp * cos(angle) - z_tmp * sin(angle);
	camera->dir.z = y_tmp * sin(angle) + z_tmp * cos(angle);
}

void		rotate_y(t_n_cam *camera)
{
	float        x_tmp;
	float        z_tmp;
	float		  angle;

	angle = (camera->rot.y * ((M_PI * 0.5f * FOV) / 180.0f));

	x_tmp = camera->dir.x;
	z_tmp = camera->dir.z;
	camera->dir.z = z_tmp * cos(angle) - x_tmp * sin(angle);
	camera->dir.x = z_tmp * sin(angle) + x_tmp * cos(angle);
}

void		rotate_z(t_n_cam *camera)
{
	float        x_tmp;
	float        y_tmp;
	float		  angle;

	angle = (camera->rot.z * ((M_PI * 0.5f * FOV) / 180.0f));

	x_tmp = camera->dir.x;
	y_tmp = camera->dir.y;
	camera->dir.x = x_tmp * cos(angle) - y_tmp * sin(angle);
	camera->dir.y = x_tmp * sin(angle) + y_tmp * cos(angle);
}

/*--------------------------------CALCUL DU RAYON------------------------------*/

void		ft_calc_ray(t_n_cam *camera, int const x, int const y, int al_tmp)
{
	float		angle;
	float		inv_width;
	float		inv_height;
	float		aspectratio;

	inv_width = 1 / (float)(WIDTH * al_tmp);
	inv_height = 1 / (float)(HEIGHT * al_tmp);
	aspectratio = (float)(WIDTH * al_tmp) / (float)(HEIGHT * al_tmp);
	angle = tanpi(0.5f * FOV / 180.0f);
	camera->dir.x = (2.0f * ((x + 0.5f) * inv_width) - 1.0f) * angle *
		aspectratio;
	camera->dir.y = (1.0f - 2.0f * ((y + 0.5f) * inv_height)) * angle;
	camera->dir.z = -1.0f;
	rotate_x(camera);
	rotate_y(camera);
	rotate_z(camera);
	camera->dir = normalize(camera->dir);
	
}

/*---------------------FONCTIONS POUR LES OBJETS INTERCEPTER-----------------------------------*/

int		sort_absfloat_tab(float *tab, int len)
{
	int		nb_hit = len;
	float	buf;

	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
			if ((tab[j] < tab[i] || tab[i] <= 0) && tab[j] > 0)
			{
				buf = tab[i];
				tab[i] = tab[j];
				tab[j] = buf;
			}
		if (tab[i] <= 0)
			nb_hit--;
	}
	return (nb_hit);
}

int			ray_dist(float discr, float b, float *t, float a, t_record  *rec)
{
	float		sqrtdiscr;
	float		t0;
	float		t1;

	sqrtdiscr = sqrt((float)discr);
	t0 = (-b + sqrtdiscr) / (2.0f * a);
	t1 = (-b - sqrtdiscr) / (2.0f * a);
	if (rec->type == 3 || rec->type == 4)
	{
			rec->res_t[0] = t1;
			rec->res_t[1] = t0;
			*t = t1;
	}
	else 
	{
		if (t0 > t1)
			t0 = t1;
		*t = t0;
	}
	return (1);
}

int			sphere_hit(t_n_cam *cam, t_object sp, float *t, t_record  *rec, float t_res)
{
	float		a;
	float		b;
	float		c;
	float4		origin = (float4)(sp.origin.x, sp.origin.y, sp.origin.z, 0.0f);
	float		discr;
	float4		dist = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	
	a = dot(cam->dir, cam->dir);
	dist = cam->ori - origin;
	b = 2.0f * dot(cam->dir, dist);
	c = dot(dist, dist) - sp.size * sp.size;
	discr = b * b - 4.0f * a * c;
	if (discr < 0.0f)
		return (0);
	if (ray_dist(discr, b, t, a, rec) && *t < t_res  && *t > 0.0001f)
	{
		rec->t = *t;
		rec->hitpoint = cam->ori + (normalize(cam->dir) * *t);
        rec->normale =  normalize(rec->hitpoint - origin);
		rec->type = 1;
	}
	return (1);
}

int			plan_hit(t_n_cam *cam, t_object pl, float *t, t_record *rec, float t_res)
{
	float4		origin = (float4)(pl.origin.x, pl.origin.y, pl.origin.z, 0.0f);
	float4		rot = normalize((float4)(pl.rot.x, pl.rot.y, pl.rot.z, 0.0f));

	cam->dir = normalize(cam->dir);
	*t = -(dot(normalize(rot), (cam->ori - origin)) / dot(rot, normalize(cam->dir)));
	if (*t <= 0)
		return (0);
	if (pl.size > 0)
    { 	
		float4 p = origin + (float4)(pl.size * 0.5, pl.size, pl.size * 0.5, 0.f);
        float4 m = origin - (float4)(pl.size * 0.5, pl.size, pl.size * 0.5, 0.f);
		float4 point = cam->ori + (*t * normalize(cam->dir));
        if(point.x > p.x || point.x < m.x || point.y > p.y || point.y < m.y || point.z > p.z || point.z < m.z)
        	return(0);
    }
	if (*t < t_res && *t > 0.0001f)
	{
		
		rec->type = 2;
		rec->normale = normalize(rot);
		if (dot(normalize(cam->dir), rec->normale) > 0)
       		 rec->normale = rec->normale * -1;
		rec->hitpoint = cam->ori + (*t * normalize(cam->dir));
		rec->t = *t;
	}
	return (1);
}


int			cone_hit(t_n_cam *cam, t_object co, float *t, t_record *rec, float t_res)
{
	float4		origin = (float4)(co.origin.x, co.origin.y, co.origin.z, 0.0f);
	float4		dir = normalize((float4)(co.rot.x, co.rot.y, co.rot.z, 0.0f));
	float4 		rdir = normalize(cam->dir);
	float4		dist = cam->ori - origin;
	float		discr;
	float		a;
	float		b;
	float		c;

	float angle2 = (1 + tan(co.size * PI180) * tan(co.size * PI180));
	float drd = dot(rdir, dir);
	float dd = dot(dist, dir);
	a = dot(rdir, rdir) - angle2 * drd * drd;
	b = 2 * (dot(rdir, dist) - angle2 * drd * dd);
	c = dot(dist, dist) - angle2 * dd * dd;
		discr = b * b - 4.0f * a * c;
	if (discr < 0)
		return (0);
	rec->type = 3;
	if (ray_dist(discr, b, t, a, rec) && *t < t_res && *t > 0.0001f)
	{
		float nb_hit = sort_absfloat_tab(rec->res_t, 2);
		float4 temp = (float4)(dir * ((drd * *t + dd) * (float)angle2));
		float4 tmp = (cam->ori + *t * cam->dir) - origin;
		if(length(tmp) > co.b_size)
		{
			nb_hit--;
			 if (nb_hit == 0)
				return (0);
			*t = rec->res_t[1];
			temp = dir * (drd * *t + dd);
			tmp = (cam->ori + *t * normalize(cam->dir)) - origin;
			if(length(tmp) > co.b_size)
				return (0);
		}
		rec->normale = 	normalize(tmp - temp);
		rec->hitpoint = cam->ori + (normalize(cam->dir) * *t);
		rec->t = *t;
		if (fabs(dot(normalize(dir), normalize(cam->ori - origin))) < co.size)
				rec->normale *= -1;
	}
	return (1);
}

int			cylinder_hit(t_n_cam *cam, t_object cyl, float *t, t_record *rec, float t_res)
{
	float4		origin = (float4){cyl.origin.x, cyl.origin.y, cyl.origin.z, 0.0f};
	float4		dir = normalize((float4){cyl.rot.x, cyl.rot.y, cyl.rot.z, 0.0f});
	float4 		rdir = normalize(cam->dir);
	float4		dist = cam->ori - origin;
	float 		drd = dot(rdir, dir);
	float 		dd = dot(dist, dir);
	float		a;
	float		b;
	float		c;
	float		discr;

	a = dot(rdir, rdir) - drd * drd;
	b = 2 * (dot(rdir, dist) - drd * dd);
	c = dot(dist, dist) - dd * dd - cyl.size * cyl.size;
	discr = b * b - 4.0f * a * c;
	if (discr < 0)
		return (0);
	rec->type = 4;
	if (ray_dist(discr, b, t, a, rec) && *t < t_res && *t > 0.0001f)
	{
		float4 temp = dir * (drd * *t + dd);
		float4 tmp = (cam->ori + *t * normalize(cam->dir)) - origin;
		float nb_hit = sort_absfloat_tab(rec->res_t, 2);
		if (sqrt(length(tmp) * length(tmp) - cyl.size * cyl.size) > cyl.b_size)
		{
			nb_hit--;
			if (nb_hit == 0)
				return (0);
			*t = rec->res_t[1];
			temp = dir * (drd * *t + dd);
			tmp = (cam->ori + *t * normalize(cam->dir)) - origin;
			if (sqrt(length(tmp) * length(tmp) - cyl.size * cyl.size) > cyl.b_size)
				return (0);
		}
		rec->t = *t;
		rec->hitpoint = cam->ori + *t * normalize(cam->dir);
		rec->normale = normalize(tmp - temp);
		if (nb_hit == 1)
			rec->normale *= -1;
	}
	return (1);
}

int triangle_hit(t_n_cam *cam, t_object tle, float *t, t_record *rec, float t_res)
{
	float4		e[2],p[2],v;
	float4		origin = (float4){tle.origin.x, tle.origin.y, tle.origin.z, 1.0f};
	float4		rot = (float4){tle.rot.x, tle.rot.y, tle.rot.z, 1.0f};
	float4		trois =  (float4){tle.trois.x, tle.trois.y, tle.trois.z, 1.0f};
	float		inv;
	float   	det;
	

    e[0] = rot - origin;
	e[1] = trois - origin;
    p[0] = cross(cam->dir, e[1]);
    if ((det = dot(e[0], p[0])), det > -0.000001 && det < 0.000001)
        return (0);
    inv = 1.0f / det;
    p[1] = cam->ori - origin;
    if ((v.x = dot(p[1], p[0]) * inv), v.x < 0 || v.x > 1)
        return (0);
    p[1] = cross(p[1], e[0]);
    if ((v.y = dot(cam->dir, p[1]) * inv), v.y < 0 || v.x + v.y > 1)
        return (0);
	if ((v.z = dot(e[1], p[1]) * inv) > 0)
	{
		*t = v.z;
		if (*t > 0.0001f && *t < t_res)
		{
			rec->t = *t;
        	rec->normale = cross(normalize(e[1]), normalize(e[0]));
			rec->type = 7;
			rec->hitpoint = cam->ori + normalize(cam->dir) * *t;
			return(1);
		}
	}
	return(0);
}

int			alter_hit(t_n_cam *cam, t_object alter, float *t, t_record *rec, float t_res)
{
	int	i;
	t_object tmp;

	i = 0;
	tmp = alter;
	if (cylinder_hit(cam, tmp, t, rec, t_res))
	{
		i++;
		t_res = *t;
		rec->type = 9;
	}
	tmp.size *= 2;
	float4 tmp_rot = normalize((float4){tmp.rot.x, tmp.rot.y, tmp.rot.z, 0.f});
	tmp.origin.x = tmp.origin.x + tmp_rot.x;
	tmp.origin.y = tmp.origin.y + tmp_rot.y;
	tmp.origin.z = tmp.origin.z + tmp_rot.z;
	if (sphere_hit(cam, tmp, t, rec, t_res))
	{
		i++;
		t_res = *t;
		rec->type = 9;
	}
	tmp.origin.x = alter.origin.x - tmp_rot.x;
	tmp.origin.y = alter.origin.y - tmp_rot.y;
	tmp.origin.z = alter.origin.z - tmp_rot.z;
	if (sphere_hit(cam, tmp, t, rec, t_res))
	{
		i++;
		t_res = *t;
		rec->type = 9;
	}
	if (i > 0)
		return (1);
	return (0);
}
/* ----------------------------- CALCUL POUR LE TORUS ----------------------------------------*/

void		solve_1(t_cub_sol sol, t_4pow *x, int *nr)
{
	double s1;
	double s2;

	s1 = sol.r + sqrt(sol.d);
	s2 = sol.r - sqrt(sol.d);
	s1 = (s1 >= 0.0) ? exp((1. / 3.) * log(s1)) : -exp((1. / 3.) * log(-s1));
	s2 = (s2 >= 0.0) ? exp((1. / 3.) * log(s2)) : -exp((1. / 3.) * log(-s2));
	x->q1 = (s1 + s2) - sol.a.q2 / 3.0;
	x->q2 = -0.5 * (s1 + s2) - sol.a.q2 / 3.0;
	x->q3 = x->q2;
	*nr = 1;
}

void		solve_2(t_cub_sol sol, t_4pow *x, int *nr)
{
	double theta;
	double costh;
	double sinth;
	double sq;
	double tmp;

	tmp = -sol.q * sol.q * sol.q;
	theta = acos(sol.r / sqrt(tmp)) / 3.0;
	costh = cos(theta);
	sinth = sin(theta);
	sq = sqrt(-sol.q);
	x->q1 = (2.0 * sq * costh - sol.a.q2 / 3.0);
	x->q2 = (-sq * costh - sol.a.q2 / 3.0 - sqrt(3.) * sq * sinth);
	x->q3 = (-sq * costh - sol.a.q2 / 3.0 + sqrt(3.) * sq * sinth);
	*nr = 3;
}

void		cubic_equation(t_4pow c, t_4pow *x, int *nr)
{
	t_cub_sol	sol;
	double		s;

	sol.a.q2 = c.q2 / c.q3;
	sol.a.q1 = c.q1 / c.q3;
	sol.a.q0 = c.q0 / c.q3;
	sol.q = sol.a.q1 / 3.0 - carre_d(sol.a.q2) / 9.0;
	sol.r = (sol.a.q1 * sol.a.q2 - 3.0 * sol.a.q0) / 6.0 - cube_d(sol.a.q2) / 27.0;
	sol.d = cube_d(sol.q) + carre_d(sol.r);
	if (sol.d > 0.0)
		solve_1(sol, x, nr);
	else if (sol.d < 0.0)
		solve_2(sol, x, nr);
	else
	{
		s = (sol.r >= 0.0) ? exp((1. / 3.) * log(sol.r)) : -exp((1. / 3.) * log(-sol.r));
		x->q1 = 2.0 * s - sol.a.q2 / 3.0;
		x->q2 = -s - sol.a.q2 / 3.0;
		x->q3 = x->q2;
		*nr = 3;
	}
}

void				find_new_sol(t_5pow d, t_4pow *a, t_4pow *new_a)
{
	a->q3 = d.q3 / d.q4;
	a->q2 = d.q2 / d.q4;
	a->q1 = d.q1 / d.q4;
	a->q0 = d.q0 / d.q4;
	new_a->q3 = 1.0;
	new_a->q2 = -a->q2;
	new_a->q1 = (a->q1 * a->q3 - 4.0 * a->q0);
	new_a->q0 = 4.0 * a->q0 * a->q2 - carre_d(a->q1) - a->q0 * carre_d(a->q3);
}

int				solveur_part_1(t_quartic_sol *sol)
{
	if (sol->ret3 != 0.0)
	{
		sol->f1 = 0.75 * carre_d(TA.q3) - sol->ret2 - 2.0 * TA.q2;
		sol->f2 = 0.25 * (4.0 * TA.q3 * TA.q2 - 8.0 * TA.q1 - cube_d(TA.q3)) / sol->ret3;
		R4 = sol->f1 + sol->f2;
		sol->ret5 = sol->f1 - sol->f2;
	}
	else
	{
		sol->f1 = 0.75 * TA.q3 * TA.q3 - 2.0 * TA.q2;
		sol->f2 = 2.0 * sqrt(carre_d(sol->ret1) - 4.0 * TA.q0);
		R4 = sol->f1 + sol->f2;
		sol->ret5 = sol->f1 - sol->f2;
	}
	return (1);
}

int				solveur_part_2(t_quartic_sol *sol)
{
	if (R4 >= 0.0)
	{
		R6 = sqrt(R4);
		sol->r.q1 = -0.25 * TA.q3 + 0.5 * sol->ret3 - 0.5 * R6;
		sol->r.q2 = -0.25 * TA.q3 + 0.5 * sol->ret3 + 0.5 * R6;
		AL = 2;
	}
	else
	{
		sol->r.q1 = -0.25 * TA.q3 + 0.5 * sol->ret3;
		sol->r.q2 = sol->r.q1;
		AL = 0;
	}
	return (1);
}

int				return_quartic(double *ret, t_quartic_sol sol)
{
	int i;

	i = 0;
	if (sol.alpha != 0)
	{
		ret[i++] = sol.r.q1;
		ret[i++] = sol.r.q2;
	}
	if (sol.beta != 0)
	{
		ret[i++] = sol.r.q3;
		ret[i++] = sol.r.q4;
	}
	return (sol.alpha + sol.beta);
}

int						quartic_solver(double *ret, t_5pow d)
{
	t_quartic_sol	sol;

	find_new_sol(d, &sol.a, &sol.new_a);
	cubic_equation(sol.new_a, &sol.x, &sol.nbr);
	if (sol.nbr == 1)
		R = sol.x.q1;
	else
		R = (sol.x.q1 > sol.x.q3) ? sol.x.q1 : sol.x.q3;
	R2 = 0.25 * carre_d(sol.a.q3) + R - sol.a.q2;
	R3 = (sol.ret2 > 0.0) ? sqrt(R2) : 0.0;
	sol.useless = solveur_part_1(&sol) + solveur_part_2(&sol);
	if (R5 >= 0.0)
	{
		R7 = sqrt(R5);
		sol.r.q3 = -0.25 * sol.a.q3 - 0.5 * R3 - 0.5 * R7;
		sol.r.q4 = -0.25 * sol.a.q3 - 0.5 * R3 + 0.5f* R7;
		sol.beta = 2;
	}
	else
	{
		sol.r.q3 = -0.25 * sol.a.q3 - 0.5 * R3;
		sol.r.q4 = sol.r.q3;
		sol.beta = 0;
	}
	return (return_quartic(ret, sol));
}

float			check_ret(double *ret)
{
	int			i;
	float		root;
	float		root_rend;

	i = -1;
	root_rend = 0;
	while (++i < 4)
	{
		root = ret[i];
		if (root > -1 && (root_rend == 0 || root < root_rend))
			root_rend = root;
	}
	return (root_rend);
}

int			torus_hit(t_n_cam *cam, t_object tor, float *t, t_record *rec, float t_res)
{
	double4		origin = (double4){tor.origin.x, tor.origin.y, tor.origin.z, 0.f};
	double4		rot = (double4){tor.rot.x, tor.rot.y, tor.rot.z, 0.f};
	double4		cam_dir = (double4){cam->dir.x, cam->dir.y, cam->dir.z, 0.f};
	double4		cam_ori = (double4){cam->ori.x, cam->ori.y, cam->ori.z, 0.f};
	double		r1;
	double		r2;
	double		a;
	double		b;
	double		c;
	double		d;
	double		m;
	double		n;
	double		o;
	double		p;
	double		q;
	t_5pow		zz;
	double		ret[4];
	int			i;
	double4		dist;
	int			det;

	rot = normalize(rot);
	dist = cam_ori - origin;
	n = dot(cam_dir, dist);

	det = n > 0.5 ? 0 : 1;

	o = dot(dist, dist);
	q = dot(rot, dist);
	m = dot(dist, cam_dir);
	p = dot(rot, cam_dir);

	r1 = carre_d(tor.size);
	r2 = carre_d(tor.b_size);

	a = 1 - carre_d(p);
	b = 2 * (m - q * p);
	c = o - carre_d(q);
	d = o + r2 - r1;

	zz.q4 = 1;
	zz.q3 = 4 * n;
	zz.q2 = 2 * d + zz.q3 * zz.q3 * 0.25 - 4 * r2 * a;
	zz.q1 = zz.q3 * d - 4 * r2 * b;
	zz.q0 = d * d - 4 * r2 * c;

	i = -1;
	while (++i < 4)
		ret[i] = -1;
	if (det == 1 && quartic_solver(ret, zz))
		if ((*t = check_ret(ret)) && *t < t_res && *t > 0.0001f)
		{
			rec->t = *t;
			double4 tmp_hitpoint = cam_ori + normalize(cam_dir) * *t;
			rec->hitpoint = cam->ori + normalize(cam->dir) * *t;
			rot = normalize(rot);
			double4 tmp_normale = normalize(tmp_hitpoint - (normalize(tmp_hitpoint - origin - (rot * dot((tmp_hitpoint - origin), rot))) * tor.b_size + origin));
			rec->normale = (float4){tmp_normale.x, tmp_normale.y, tmp_normale.z, 0.f};
			rec->type = 6;
			return (1);
		}
	return (0);
}


/*-------------------------------FONCTION DE TRACE----------------------------------------*/


int			trace(t_n_cam *camera, global t_object *obj, int nb, int *hitobject, float *tnear, int light_or_not, t_record  *rec)
{
	float		tneark;
	int			i;

	i = -1;
	while (++i < nb)
	{
		tneark = FLT_MAX;
		if (obj[i].type == 1 || (obj[i].type == 5 && !light_or_not))
		{
			
			if (sphere_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 2)
		{
			
			if (plan_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 3)
		{
			if (cone_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 4)
		{
			if (cylinder_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 6)
		{
			if (torus_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 7)
		{
			if (triangle_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
		else if (obj[i].type == 9)
		{
			if (alter_hit(camera, obj[i], &tneark, rec, *tnear) && tneark < *tnear && tneark > 0.0001f)
			{
				rec->hitobject = i;
				*hitobject = i;
				*tnear = tneark;
			}
		}
	}
	return (*hitobject != -1);
}

/*-------------------------FONCTIONS POUR LES COULEURS------------------------------------------*/

void		fsdl_draw_pt(__global unsigned char *data, __constant  t_opencl *opencl, int clr, int x, int y)
{
	*((__global unsigned int *)(data + y * opencl->sizeline + x * opencl->bpp)) = clr;
}

int 	get_color_bis(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (((a & 255) << 24) + ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF)));
}

void   get_rgb_from_int(int col, t_color *color)
{
	color->r = (float)((col >> 16) & 255) / 255.0f;
	color->g = (float)((col >> 8) & 255) / 255.0f;
	color->b = (float)((col) & 255) / 255.0f;
}

/*----------------------------BRUIT DE PERLIN---------------------------------------------*/

float      lerp(float t, float a, float b) 
{
    return (a + t * (b - a));
}

float      fade(float t)
{
    return (t * t * t * (t * (t * 6 - 15) + 10));
}

float      grad(int hash, float x, float y, float z) 
{
    int h;
    float u;
    float v;

    h = hash & 15;
    u = h < 8 || h == 12 || h == 13 ? x : y;
    v = h < 4||h == 12||h == 13 ? y : z;
    return ((h & 1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
}

void perlin (int *p, __constant  t_opencl *opencl)
{
	int		j;
	
    j = -1;
    while (++j < 256)
    {
        p[256 + j] = opencl->permutation[j];
        p[j] = opencl->permutation[j];
    }
}

float       noise(float4 vector, __constant  t_opencl *opencl)
{
	int      		   p[512];
    float               u;
    float               v;
    float               w;
	int					a;
	int					aa;
	int					ab;
	int					b;
	int					bb;
	int					ba;
	int					xx;
	int					yy;
	int					zz;

    perlin(p, opencl);
	xx = (int)floor(vector.x) & 255;
    yy = (int)floor(vector.y) & 255;
    zz = (int)floor(vector.z) & 255;
	vector.x -= floor(vector.x);
    vector.y -= floor(vector.y);
    vector.z -= floor(vector.z);
	u = fade(vector.x);
    v = fade(vector.y);
    w = fade(vector.z);
	a = p[xx] + yy;
    aa = p[a] + zz;
    ab = p[a + 1] + zz;
    b = p[xx + 1] + yy;
    ba = p[b] + zz;
    bb = p[b + 1] + zz;
    return (lerp(w, lerp(v, lerp(u, grad(p[aa], vector.x, vector.y, vector.z),
        grad(p[ba], vector.x-1, vector.y, vector.z)),
        lerp(u, grad(p[ab], vector.x, vector.y-1, vector.z),
        grad(p[bb], vector.x-1, vector.y-1, vector.z))),
        lerp(v, lerp(u, grad(p[aa + 1], vector.x, vector.y, vector.z - 1),
        grad(p[ba + 1], vector.x - 1, vector.y, vector.z - 1)),
        lerp(u, grad(p[ab + 1], vector.x, vector.y - 1, vector.z - 1 ),
        grad(p[bb + 1], vector.x - 1, vector.y - 1, vector.z - 1 )))));
}

t_color     wood(float p, float4 hitpoint, t_color obj_col, __constant  t_opencl *opencl)
{
    float  	 noisecoef;
    int      k;
	float  	 v;
    float4   scaled;
    t_color  rgb;
    
    noisecoef = 0.0f;
    p /= 10;
    scaled = hitpoint * p;
    noisecoef = fabs(noise(scaled, opencl));
    v = 20 * noisecoef;
    k = (int)v;
    v = v - k;
    rgb.r = obj_col.r * ((v * 0.4) + (1 - v) * 0.1 );
    rgb.g = obj_col.g * ((v * 0.4) + (1 - v) * 0.1 );
    rgb.b = obj_col.b * ((v * 0.4) + (1 - v) * 0.1 );
    return(rgb);
}

t_color     marbre(float p, float4 hitpoint, t_color obj_col, __constant  t_opencl *opencl)
{
    int      level;
    float    noisecoef;
    float4   tmp = (float4){0.f, 0.f, 0.f, 0.f};
    t_color  tex;

    level = 0;
    noisecoef = 0.0f;
    while (++level < 15)
    {
        tmp.x = level * 0.55f * hitpoint.x * p;
        tmp.y = level * 0.55f * hitpoint.y * p;
        tmp.z = level * 0.55f * hitpoint.z * p;
        noisecoef += (1.0f / level) * fabs(noise(tmp,opencl));
    }
    noisecoef = 0.5f * sinf((hitpoint.x * p + hitpoint.y * p) * 0.5f + noisecoef) + 0.5f;
	tex.r = obj_col.r * ((noisecoef * 0.8) + (1 - noisecoef) * 0.2);
	tex.g = obj_col.g * ((noisecoef * 0.8) + (1 - noisecoef) * 0.2);
	tex.b = obj_col.b * ((noisecoef * 0.8) + (1 - noisecoef) * 0.2);
    return (tex);
}
void	normal_water(double d, t_record *rec, float4 inter, float4 dir, int texture, __constant  t_opencl *opencl)
{
	float4 tall;
	float4 ret;

    (void)texture;

	if (fabs(dir.y) > fabs(dir.x) && fabs(dir.y) > fabs(dir.z))
    {
        tall.x = rec->normale.x + inter.x;
        tall.y = 50 * rec->normale.y + 100 * inter.y;
        tall.z = rec->normale.z + inter.z;
    }

	else if (fabs(dir.x) > fabs(dir.y) && fabs(dir.x) > fabs(dir.z))
    {
        tall.x = 50 * rec->normale.x + 100 * inter.x;
        tall.y = rec->normale.y + inter.y;
        tall.z = rec->normale.z + inter.z;
    }

	else if (fabs(dir.z) > fabs(dir.x) && fabs(dir.z) > fabs(dir.y))
    {
        tall.x = rec->normale.x + inter.x;
        tall.y = rec->normale.y + inter.y;
        tall.z = 50 * rec->normale.z + 100 * inter.z;
    }

    ret.x = ((float)noise((float4){tall.x - d, tall.y, tall.z, 0}, opencl)) + ((float)noise((float4){tall.x + d, tall.y, tall.z, 0}, opencl));
    ret.y = ((float)noise((float4){tall.x, tall.y - d, tall.z, 0}, opencl)) + ((float)noise((float4){tall.x, tall.y + d, tall.z, 0}, opencl));
    ret.z = ((float)noise((float4){tall.x, tall.y, tall.z - d, 0}, opencl)) + ((float)noise((float4){tall.x, tall.y, tall.z + d, 0}, opencl));
	rec->normale.x += ret.x;
	rec->normale.y += ret.y;
	rec->normale.z += ret.z;
}

int        checker_tex(float4 hitpoint)
{
    float sines;

    sines = sin(10 * hitpoint.x) * sin(10 * hitpoint.y) * sin(10 * hitpoint.z);
    if (sines < 0)
        return (1);
	return (0);
}

void        modif_normale(double density, t_record *rec, float4 hitpoint, __constant  t_opencl *opencl)
{
    float4 tmp;
    float noisecoefx;
    float noisecoefy;
    float noisecoefz;
    float          len;
    float          sq;

    hitpoint = hitpoint * 8;
    noisecoefx = (float)(noise(hitpoint, opencl));
    noisecoefy = (float)(noise(hitpoint, opencl));
    noisecoefz = (float)(noise(hitpoint, opencl));
    tmp.x = (1 - density )
        *   rec->normale.x + density * noisecoefx;
    tmp.y = (1 - density )
        *   rec->normale.y + density * noisecoefy;
    tmp.z = (1 - density )
        *   rec->normale.z + density * noisecoefz;
    tmp = normalize(tmp);
    len = length(tmp);
    sq = len * len;
    if (sq == 0.0f)
        return;
    else
    {
    	sq = 1 / sq;
    	rec->normale = sq * tmp;
    	rec->normale = normalize(rec->normale);
    }
 }

t_color        proc_tex(__constant  t_opencl *opencl, int hitobject, __global t_object *tab, t_n_cam *camera, t_record *rec)
{
    float4       tmp3 = (float4){0.f, 0.f, 0.f, 0.f};
    t_color      texcol;
	float		 scale;
    float4		 hit_ori = (float4){tab[hitobject].origin.x, tab[hitobject].origin.y, tab[hitobject].origin.z, 0.f};	
	float4 		hit_rot = (float4){tab[hitobject].rot.x, tab[hitobject].rot.y, tab[hitobject].rot.z, 0.f};

    tmp3 = normalize(rec->hitpoint - hit_ori);
    texcol.r = 0.0f;
    texcol.g = 0.0f;
    texcol.b = 0.0f;
	texcol = tab[hitobject].color;
	if (tab[hitobject].texture == 5 && tab[hitobject].type == 2)
	 	normal_water(opencl->density, rec, rec->hitpoint - hit_ori, hit_rot, tab[hitobject].texture, opencl); 
	if (tab[hitobject].texture == 11)
		modif_normale(opencl->density, rec, rec->hitpoint - hit_ori, opencl);
    if (tab[hitobject].texture == 2)
    {
        if ((checker_tex(rec->hitpoint)))
        {
            texcol.r = 10.0f * 0.18 / M_PI;
            texcol.g = 10.0f * 0.18 / M_PI;
            texcol.b = 10.0f * 0.18 / M_PI;
        }
        else
        {
            texcol.r = 60.0f * 0.18 / M_PI;
            texcol.g = 60.0f * 0.18 / M_PI;
            texcol.b = 60.0f * 0.18 / M_PI;    
        }
    }
    else if (tab[hitobject].texture == 3)
    {
        scale = 10.0f;
		texcol = marbre(scale, tmp3, texcol, opencl);
    }
	else if (tab[hitobject].texture == 4)
    {
        scale = 22.0f;
		texcol = wood(scale, tmp3, texcol, opencl);
    } 
    return (texcol);
}
/*----------------------------FIN BRUIT DE PERLIN---------------------------------------------*/


void    texture_mapping(int *i, int *j, global t_object *tab, int hitobject, void *surf, t_n_cam *cam, int w, int h, float t)
{
    float4           hitpoint = (float4){0.f, 0.f, 0.f, 0.f};
	float4           vec_scaled;
    double 			 phi;
    double 			 theta;
    float 			 u;
    float 			 v;
	float4			 hit_ori = (float4){tab[hitobject].origin.x, tab[hitobject].origin.y, tab[hitobject].origin.z, 0.f};			

    vec_scaled = cam->dir * t;
	hitpoint = cam->ori + vec_scaled;
    hitpoint = hitpoint - hit_ori;
    hitpoint = hitpoint * (1.0f / (float)tab[hitobject].size);
    phi = atan2(hitpoint.z, hitpoint.x);
    theta = asin(hitpoint.y);
    u = 1 - (phi + M_PI) / (2 * M_PI);
    v = (theta + M_PI / 2) / M_PI;
    *i = u * w ;
    *j = (1 - v) * h - 0.001;
    (*i < 0) ? *i = 0 : 0;
    (*j < 0) ? *j = 0 : 0;
    (*i > w  - 1) ? *i = w   - 1 : 0;
    (*j > h  - 1) ? *j = h - 1 : 0;
}

t_color    load_tex(__constant  t_opencl *opencl, int hitobject, global t_object *tab, t_n_cam *camera, float t)
{
	int		i;
	int		j;
	int		w;
	int		h;
	int		aa;
	int		texcol;
	int		pitch;
	int		bpp;
	char	*surf;
    t_color tmp;

    if (tab[hitobject].texture == 10)
	{
		w = opencl->w1;
		h = opencl->h1;
		surf = opencl->data1;
		pitch = opencl->size_t1;
		bpp = opencl->bpp1;
	}
    else if (tab[hitobject].texture == 6)
	{
		w = opencl->w2;
		h = opencl->h2;
		surf = opencl->data2;
		pitch = opencl->size_t2;
		bpp = opencl->bpp2;
	}
    else if (tab[hitobject].texture == 7 )
	{
		w = opencl->w3;
		h = opencl->h3;
		surf = opencl->data3;
		pitch = opencl->size_t3;
		bpp = opencl->bpp3;
	}
    else if (tab[hitobject].texture == 8)
	{
		w = opencl->w4;
		h = opencl->h4;
		surf = opencl->data4;
		pitch = opencl->size_t4;
		bpp = opencl->bpp4;
	}
    else if (tab[hitobject].texture == 9)
	{
		w = opencl->w5;
		h = opencl->h5;
		surf = opencl->data5;
		pitch = opencl->size_t5;
		bpp = opencl->bpp5;
	}
    tmp.r = 0.0f;
    tmp.g = 0.0f;
    tmp.b = 0.0f;
	texture_mapping(&i, &j, tab, hitobject, surf, camera, w * 2, h  , t);
	aa = j * (pitch ) + i * bpp;
	texcol = *((int*)(surf + aa));
	get_rgb_from_int(texcol, &tmp);
	return (tmp);
}

/*--------------------------------------CALCUL DE LA LUMIERE---------------------------------------*/

float4 				reflect(float4 i, float4 n)
{
	return (i -  2.0f * dot(i, n) * n);
}

void 				assign_new_ray(__global t_object *tab, t_n_cam *ray, t_n_cam *source, int hitobject, float t, t_record rec, int r)
{
	if (r == 1)
	{
		ray->dir = reflect(source->dir, rec.normale);
		ray->dir = normalize(ray->dir);
		ray->ori = rec.hitpoint;
	}
}

t_color 			fill_final_color(t_color object_color, t_color material_color, __global t_object *tab, t_record *rec)
{
	t_color 	final_color;

	final_color.r = object_color.r * (1 - tab[rec->hitobject].reflection) + material_color.r * tab[rec->hitobject].reflection;
	final_color.g = object_color.g * (1 - tab[rec->hitobject].reflection) + material_color.g * tab[rec->hitobject].reflection;
	final_color.b = object_color.b * (1 - tab[rec->hitobject].reflection) + material_color.b * tab[rec->hitobject].reflection;
	return (final_color);
}

t_color 			reflect_ray(__constant 	t_opencl *opencl, __global t_object *tab, int nb, t_n_cam *camera, int hitobject, t_record rec[10])
{
	t_n_cam 		reflect_cam;
	t_n_cam 		tmp_cam;
	t_color 		reflect_color;
	t_color 		tmp_color;
	int 			hitobject_tmp;
	float 			coef;
	int  			level;
	t_record 		rec_tmp[10];
	float 			t_tmp;
	int 			stop;

	reflect_color.r = 0;
	reflect_color.g = 0;
	reflect_color.b = 0;
	tmp_color.r = 0;
	tmp_color.g = 0;
	tmp_color.b = 0;
	coef = 1;
	level = 0;
	stop = 0;
	hitobject_tmp = -1;
	assign_new_ray(tab, &reflect_cam, camera, hitobject, rec[0].t, rec[0], 1);
	t_tmp = FLT_MAX;
	while (++level < 5 && trace(&reflect_cam, tab, nb, &hitobject_tmp, &t_tmp, 0, &rec_tmp[level - 1]) && stop == 0)
	{
		rec_tmp[level - 1].color = get_texture(opencl, hitobject_tmp, tab, &reflect_cam, &rec_tmp[level - 1]);			
		if (tab[hitobject_tmp].reflection != 0)
		{
			tmp_cam = reflect_cam;
			coef *= (tab[hitobject_tmp].reflection < 1) ? tab[hitobject_tmp].reflection * 1.1 :  tab[hitobject_tmp].reflection;
			tmp_color = apply_light(opencl, hitobject_tmp, tab, nb, rec_tmp[level - 1], &reflect_cam);
			tmp_color.r /= 255.f;
			tmp_color.g /= 255.f;
			tmp_color.b /= 255.f;
			tmp_color.r *= 1 - coef;
			tmp_color.g *= 1 - coef;
			tmp_color.b *= 1 - coef;
			assign_new_ray(tab, &reflect_cam, &tmp_cam, hitobject_tmp, rec_tmp[level - 1].t, rec_tmp[level - 1], 1);
		}
		else
		{
			tmp_color = apply_light(opencl, hitobject_tmp, tab, nb, rec_tmp[level - 1], &reflect_cam);
			tmp_color.r /= 255.f;
			tmp_color.g /= 255.f;
			tmp_color.b /= 255.f;
			tmp_color.r *= coef;
			tmp_color.g *= coef;
			tmp_color.b *= coef;
			stop = 1;
		}
		reflect_color.r += tmp_color.r;
		reflect_color.g += tmp_color.g;
		reflect_color.b += tmp_color.b;
		reflect_color.r = clamp(reflect_color.r, 0., 1.);
		reflect_color.g = clamp(reflect_color.g, 0., 1.);
		reflect_color.b = clamp(reflect_color.b, 0., 1.);
		hitobject_tmp = -1;
		t_tmp = FLT_MAX;
	}
	return (reflect_color);
}

t_color 			get_texture(__constant t_opencl *opencl, int hitobject, __global t_object *tab, t_n_cam *camera, t_record *rec)
{
	t_color 		final_color;
	
	final_color = tab[hitobject].color;	
	if (tab[hitobject].texture > 5 && tab[rec->hitobject].texture < 11 && tab[rec->hitobject].type == 1)
		final_color = load_tex(opencl, hitobject, tab, camera, rec->t);
	else if ((tab[hitobject].texture >= 2 &&  tab[rec->hitobject].texture < 6) || tab[hitobject].texture == 11)
		final_color = proc_tex(opencl, hitobject, tab, camera, rec);
	
	return (final_color);
}

t_color 			color_light(__constant  t_opencl *opencl, int hitobject, __global t_object *tab, int  nb, t_n_cam *camera, float t, t_record rec[10])
{
	t_color 	object_color;
	t_color 	material_color;
	t_color 	final_color;
	t_color 	tmp_color;

	rec[0].semit = -1;
	object_color.r = 0;
	object_color.g = 0;
	object_color.b = 0;
	tmp_color.r = 0;
	tmp_color.g = 0;
	tmp_color.b = 0;
	material_color.r = 0;
	material_color.g = 0;
	material_color.b = 0;
	rec[0].color.r = 0;
	rec[0].color.g = 0;
	rec[0].color.b = 0;
	final_color.r = 0;
	final_color.g = 0;
	final_color.b = 0;
	rec[0].color = get_texture(opencl, hitobject, tab, camera, &rec[0]);
	if (tab[rec[0].hitobject].reflection != 0)
		material_color = reflect_ray(opencl, tab, nb, camera, hitobject, rec);
	tmp_color.r = material_color.r;
	tmp_color.g = material_color.g;
	tmp_color.b = material_color.b;
	material_color.r = fmin(tmp_color.r * 255.0f, 255);
	material_color.g = fmin(tmp_color.g * 255.0f, 255);
	material_color.b = fmin(tmp_color.b * 255.0f, 255);
	object_color = apply_light(opencl, rec[0].hitobject, tab, nb, rec[0], camera);
	final_color = fill_final_color(object_color, material_color, tab, &rec[0]);
	return (final_color);
}

t_color 			apply_light(__constant t_opencl *opencl, int hitobject, __global t_object *tab, int nb, t_record rec, t_n_cam *camera)
{
	t_n_cam cam_tmp;
	float4 	reflection_dir = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	float4 	vec_dist = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	float4 	new_light = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	float4 	neg_vec_dist = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	float4 	hitpoint = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	float4 	normale = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	int		inshadow;
	float 	tnearshadow;
	t_color final_col;
	float 	r;
	float 	g;
	float 	b;
	int 	i;
	float 	coef;
	float 	angle;
	float 	specular;
	float 	distance2;
	t_record rec_tmp;
	int 	hitobject_tmp;
	char	nb_light = 0;

	hitpoint = rec.hitpoint;
	normale = rec.normale;
	hitobject_tmp = -1;
	coef = 0.00f;
	angle = 0.f;
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	if (tab[hitobject].type == 5)
	{
		r = tab[hitobject].color.r;
		g = tab[hitobject].color.g;
		b = tab[hitobject].color.b;
	}
	else
	{
		i = -1;
		while (++i < nb)
		{
			if (tab[i].type == 5)
			{
				nb_light = 1;
				specular = 0.00f;
				inshadow = 0;
				tnearshadow = FLT_MAX;
				new_light = (float4)(tab[i].origin.x, tab[i].origin.y, tab[i].origin.z, 0.0f);
				vec_dist = new_light - hitpoint;
				distance2 = sqrt((float)dot(vec_dist, vec_dist));
				vec_dist = normalize(vec_dist);
				cam_tmp.ori = hitpoint;
				cam_tmp.dir = vec_dist;
				if (trace(&cam_tmp, tab, nb, &hitobject_tmp, &tnearshadow, 1, &rec_tmp))
				{
					if (tnearshadow < distance2)
						inshadow = 1;
				}
				if (!inshadow)
				{
					if (dot(camera->dir, normale) > 0.0f)
						normale *= -1.0f;
					neg_vec_dist = vec_dist * -1.0f;
					reflection_dir = reflect(neg_vec_dist, normale);
					specular = pow((float)fmax(0.0f, dot((float4)reflection_dir, (float4)camera->dir) * -1.0f), (20.0f * (1.f / (float)tab[i].size)));
					vec_dist = hitpoint - new_light;
					coef = 1.0f / sqrt(dot(vec_dist, vec_dist));
					vec_dist = normalize(vec_dist);
					angle = dot(vec_dist, -normale);
					if (angle <= 0)
					{
						final_col.r = 0;
						final_col.g = 0;
						final_col.b = 0;
					}
					else
					{
						if (tab[hitobject].type == 1 || tab[hitobject].type == 4 || tab[hitobject].type  == 3)
						{
							r += (rec.color.r * angle + (tab[i].color.r * specular)) * tab[i].size * coef * 10.0f; // PROBLEME rec.color = 0
							g += (rec.color.g * angle + (tab[i].color.g * specular)) * tab[i].size * coef * 10.0f;
							b += (rec.color.b * angle + (tab[i].color.b * specular)) * tab[i].size * coef * 10.0f;
						}
						else
						{
							r += (rec.color.r * angle * tab[i].color.r) * tab[i].size * coef * 10.0f;
							g += (rec.color.g * angle * tab[i].color.g) * tab[i].size * coef * 10.0f;
							b += (rec.color.b * angle * tab[i].color.b) * tab[i].size * coef * 10.0f;
						}
					}
				}
			}
		}
		if (i == nb && nb_light == 0)
			{
				specular = 0.00f;
				inshadow = 0;
				tnearshadow = FLT_MAX;
				vec_dist = camera->ori - hitpoint;
				distance2 = sqrt((float)dot(vec_dist, vec_dist));
				vec_dist = normalize(vec_dist);
				if (dot(camera->dir, normale) > 0.0f)
					normale *= -1.0f;
				neg_vec_dist = vec_dist * -1.0f;
				reflection_dir = reflect(neg_vec_dist, normale);
				specular = pow((float)fmax(0.0f, dot((float4)reflection_dir, (float4)camera->dir) * -1.0f), (20.0f * (1.f / (float)tab[i].size)));
				vec_dist = hitpoint - camera->ori;
				coef = 1.0f / sqrt(dot(vec_dist, vec_dist));
				vec_dist = normalize(vec_dist);
				angle = dot(vec_dist, -normale);
				if (angle <= 0)
				{
					final_col.r = 0;
					final_col.g = 0;
					final_col.b = 0;
				}
				else
					{
						if (tab[hitobject].type == 1 || tab[hitobject].type == 4 || tab[hitobject].type  == 3)
						{
							r += (rec.color.r * angle + ((1 * opencl->ambiante) * specular));
							g += (rec.color.g * angle + ((1 * opencl->ambiante) * specular));
							b += (rec.color.b * angle + ((1 * opencl->ambiante) * specular));
						}
						else
						{
							r += (rec.color.r * angle * (1 * opencl->ambiante));
							g += (rec.color.g * angle * (1 * opencl->ambiante));
							b += (rec.color.b * angle * (1 * opencl->ambiante));
						}
					}
			}
	}
	float exposure = -1.00f;
	if (tab[hitobject].type != 5)
	{
		b = 1.0f - expf(b * exposure);
		r = 1.0f - expf(r * exposure);
		g = 1.0f - expf(g * exposure);
	}
	final_col.r = fmin(r * 255.0f, 255);
	final_col.g = fmin(g * 255.0f, 255);
	final_col.b = fmin(b * 255.0f, 255);
	return (final_col);
}
/*-------------------------------------FILTER COLOR--------------------------------------------------------*/

void	filter_color(__constant t_opencl *opencl, t_color *final_color)
{
	t_color tmp = {0,0,0,0};
    if (opencl->filter == 1)
    {
        tmp.r = fmin(final_color->r * 0.393 + final_color->g * 0.769 + final_color->b * 0.189, 255);
        tmp.g = fmin(final_color->r * 0.349 + final_color->g * 0.686 + final_color->b * 0.168, 255);
        tmp.b = fmin(final_color->r * 0.272 + final_color->g * 0.534 + final_color->b * 0.131, 255);
		final_color->r = tmp.r;
		final_color->g = tmp.g;
		final_color->b = tmp.b;
    }
    if (opencl->filter == 2)
    {
        final_color->r = 255 - final_color->r;
        final_color->g = 255 - final_color->g;
        final_color->b = 255 - final_color->b;
    }
	if (opencl->filter == 3)
    {
        final_color->r = final_color->b;
        final_color->g = final_color->b;
        final_color->b = final_color->b;
    }
	if (opencl->filter == 4)
    {
        tmp.r = round(0.299*final_color->r + 0.587*final_color->g + 0.114*final_color->b);
        tmp.g = round(0.299*final_color->r + 0.587*final_color->g + 0.114*final_color->b);
        tmp.b = round(0.299*final_color->r + 0.587*final_color->g + 0.114*final_color->b);
 		final_color->r = tmp.r;
		final_color->g = tmp.g;
		final_color->b = tmp.b;
    }
	if (opencl->filter == 5)
    {
        final_color->r = final_color->r;
        final_color->g = 0;
        final_color->b = 0;
    }
	if (opencl->filter == 6)
    {
        final_color->r = 0;
        final_color->g = final_color->g;
        final_color->b = 0;
    }
	if (opencl->filter == 7)
    {
        final_color->r = 0;
        final_color->g = 0;
        final_color->b = final_color->b;
    }
}


__kernel void		draw_rt(__global unsigned char *data, __constant  t_opencl *opencl, global t_object *tab,
					__constant  int *nb, __global t_camera *cam, __constant int *data_offset_x, __constant int *data_offset_y)
{
	int 		x = get_global_id(0) * 10 + *data_offset_x;
	int  		y = get_global_id(1) * 10 + *data_offset_y;
	t_n_cam		new_camera;
	int			hitobject = -1;
	float		tnear = FLT_MAX;
	t_color		col_tmp = {0.f, 0.f, 0.f};
	int			x_tmp;
	int			y_tmp;
	int			xx;
	int			yy;
	int			al_tmp = 1;
	t_record    rec[10];
	t_color 	final_color = {0.f, 0.f, 0.f};

	// Initialisation de la camera //
	new_camera.ori = (float4){cam->origin.x, cam->origin.y, cam->origin.z, 0.f};
	new_camera.rot = (float4){cam->rot.x, cam->rot.y, cam->rot.z, 0.f};
	new_camera.dir = (float4){cam->dir.x, cam->dir.y, cam->dir.z, 0.f};

	// SI ON SE DEPLACE ON FAIT PAS L'ANTIALIASING ET ON CALCUL UN PIXEL SUR OPENCL->DEPTH //
	x_tmp = x;
	y_tmp = y;
	if (opencl->al > 1)
	{
		al_tmp = opencl->al;
		x_tmp *=  opencl->al;
		y_tmp *= opencl->al;
	}
	if (opencl->moove)
	{
		al_tmp = 1;
		x_tmp = x;
		y_tmp = y;
	}
	yy = -1;
	while (++yy < al_tmp)
	{
		xx = -1;
		while (++xx < al_tmp)
		{
			ft_calc_ray(&new_camera, x_tmp + xx, y_tmp + yy, al_tmp);
			if (trace(&new_camera, tab, *nb, &hitobject, &tnear, 0, &rec[0]))
				col_tmp = color_light(opencl, hitobject, tab, *nb, &new_camera, tnear, rec);
			else
				col_tmp = (t_color){0, 0, 0};

			// JE CUMULE LA COULEUR ICI SI ON A L'ANTIALIASING, SINON ON l'ECRIT POUR UN PIXEL NORMALEMENT //
			final_color.r += col_tmp.r;
			final_color.g += col_tmp.g;
			final_color.b += col_tmp.b;
		}
	}

	// SI ON A L'ANTIALIASING D'ACTIVER JE DIVISE LA COULEUR CALCULER PAR LE CARRE DE OPENCL->AL //
	if (al_tmp > 1)
	{
		final_color.r /= (al_tmp * al_tmp);
		final_color.g /= (al_tmp * al_tmp);
		final_color.b /= (al_tmp * al_tmp);
	}

	// PUIS J'ECRIS LE PIXEL TROUVER NORMALEMENT //
	filter_color(opencl, &final_color);
	fsdl_draw_pt(data, opencl, get_color_bis(final_color.r, final_color.g, final_color.b, 255), x, y);

	// SI ON SE DEPLACE VU QU'ON CALCUL UN PIXEL TOUT LES OPENCL->DEPTH, J'ECRIS LES PIXELS ENTRE AVEC LA COULEUR TROUVER AU DESSUS POUR NE PAS AVOIR DE TROUS NOIRS //
	if (*data_offset_x == 0 && *data_offset_y == 0 && al_tmp == 1 && opencl->motion_b == 0)
	{	
		yy = -1;
		while (++yy < 10)
		{
			xx = -1;
			while (++xx < 10)
				fsdl_draw_pt(data, opencl, get_color_bis(final_color.r, final_color.g, final_color.b, 255), x + xx, y + yy);
		}
	}
}