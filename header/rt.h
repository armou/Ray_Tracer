/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:04:30 by ddufour           #+#    #+#             */
/*   Updated: 2017/10/05 23:10:44 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define DEG_TO_RAD(x) (x * ((M_PI * 0.5 * FOV) / 180))

# define WIDTH 1200
# define HEIGHT 800
# define FOV 45
# define HEXA "0123456789ABCDEF"
# define DECI "0123456789"

# define MOOVE rtv1->moove
# define FRONT (1 << 0)
# define BACK (1 << 1)
# define LEFT (1 << 2)
# define RIGHT (1 << 3)

# define ROT_RIGHT (1 << 4)
# define ROT_LEFT (1 << 5)
# define ROT_TOP (1 << 6)
# define ROT_BOT (1 << 7)
# define ROT_Z (1 << 12)
# define DEROT_Z (1 << 13)

# define STEP_MOVE_CAM 0.1
# define STEP_ROT_CAM 0.05
# define STEP_MOVE_OBJ 0.2
# define STEP_ROT_OBJ 0.05
# define STEP_SIZE_UPDOWN 0.1

# define WALK (1 << 8)
# define DEWALK (1 << 9)

# define MINUS (1 << 10)
# define PLUS (1 << 11)
# define FONT "Libs/arial.ttf"

# define INV_WIDTH  1 / WIDTH
# define INV_HEIGHT  1 / HEIGHT
# define ASPECTRATIO  WIDTH / HEIGHT
# define ANGLE	tan(M_PI * 0.5 * FOV / 180.)

# include "vector.h"
# include "objects.h"
# include "../Libs/libft/libft.h"
# include <math.h>
# include "quartic.h"
# include <time.h>

# include "../Libs/frameworks/SDL2.framework/Headers/SDL.h"
# include "../Libs/frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../Libs/frameworks/SDL2_image.framework/Headers/SDL_image.h"

# define MAX_SOURCE_SIZE 100000

typedef struct				s_cl
{
	cl_platform_id			platform;
	cl_device_id			device;
	cl_uint					num_entries;
	cl_context				context;
	cl_context_properties	properties[3];
	cl_command_queue		command_queue;
	cl_program				program;
}							t_cl;

typedef struct				s_kernel
{
	cl_kernel				kernel;
	cl_event				event;
	char					*function_name;
}							t_kernel;

typedef struct				s_opencl
{
	cl_int					bpp;
	cl_int					sizeline;
	cl_int					depth;
	cl_int					moove;
	cl_int					al;
	cl_int					size_t1;
	cl_int					size_t2;
	cl_int					size_t3;
	cl_int					size_t4;
	cl_int					size_t5;
	cl_int					w1;
	cl_int					w2;
	cl_int					w3;
	cl_int					w4;
	cl_int					w5;
	cl_int					h1;
	cl_int					h2;
	cl_int					h3;
	cl_int					h4;
	cl_int					h5;
	cl_int					bpp1;
	cl_int					bpp2;
	cl_int					bpp3;
	cl_int					bpp4;
	cl_int					bpp5;
	cl_char					*data1;
	cl_char					*data2;
	cl_char					*data3;
	cl_char					*data4;
	cl_char					*data5;
	cl_int					permutation[256];
	cl_float				density;
	cl_int					filter;
	cl_int					motion_b;
	cl_float				ambiante;
}							t_opencl;
typedef struct				s_cl_buffer
{
	cl_mem					data;
	cl_mem					opencl;
	cl_mem					object;
	cl_mem					nb_object;
	cl_mem					camera;
	cl_mem					work_group;
	cl_mem					work_group2;
}							t_cl_buffer;
typedef struct				s_rt
{
	SDL_Window				*window;
	SDL_Surface				*screen;
	SDL_Event				event;
	SDL_Surface				*t1;
	SDL_Surface				*t2;
	SDL_Surface				*t3;
	SDL_Surface				*t4;
	SDL_Surface				*t5;
	char					*comment;
	int						aliasing;
	int						alia_tmp;
	int						run;
	float					t;
	double					coef;
	int						moove;
	t_pos					hitpoint;
	t_pos					vec_scaled;
	t_camera				camera;
	int						nb_object;
	t_object				*tab_object;
	t_object				*object;
	t_cl					cl;
	SDL_Surface				*screen_tmp;
	t_cl_buffer				cl_b;
	t_kernel				kernel;
	t_opencl				opencl;
	cl_int					xx;
	int						motion_blur;
	t_object				*tmp_obj;
	float					cam_tmp_x;
	float					cam_tmp_y;
	float					cam_tmp_z;
	int						offset_x;
	int						offset_y;
	float					density;
	int						filter;
	t_camera				lol;
	float					ambiante;
}							t_rt;

int							stock_texture(char **file);
float						stock_b_size(char **file);
int							f_error(char *error_msg, char *file_error);
int							get_color(char **str, t_color *o_color);
void						next_car(char *file, int *i, char c);
int							stock_origin(char **file, t_pos *origin);
float						stock_size(char **file);
float						stock_reflection(char **file);
int							stock_rotation(char **file, t_pos *rot);
char						*delete_str_in_str(char *big, char *little,\
												int size);
int							stock_object(char *file, t_rt *rtv1);
int							check_balise(char *scene, char *first);
char						*stock_balise(char **scene, char *first,\
											char *second);
char						*delete_space(char *file);
int							stock_trois(char **file, t_pos *rot);
int							list_info(char *str, t_rt *rtv1);
int							check_obj_bis(char **scene, char **tmp);
int							check_obj(char **scene, char **tmp);
int							parse_scene(t_rt *rtv1, char *scene);
int							parse_camera(t_rt *rtv1, char *camera);
int							parse_object(t_rt *rtv1, char *object);
float						stock_size_plan(char **file);
t_camera					ray_for_move(t_rt *rtv1);
void						rotate_zz(t_camera *camera);
void						rotate_yy(t_camera *camera);
void						rotate_xx(t_camera *camera);
void						modif_float(double *a, double *b, double *c,\
										double step);
void						cam_move_right(t_rt *rtv1);
void						rot_move2(t_rt *rtv1);
void						rot_move(t_rt *rtv1);
void						cam_move_front(t_rt *rtv1);
void						cam_move_walk(t_rt *rtv1);
void						cam_move_back(t_rt *rtv1);
void						cam_move_dewalk(t_rt *rtv1);
void						cam_move_left(t_rt *rtv1);
t_pos						rot_obj(t_pos vec, t_pos rot);
void						event_antialiasing(t_rt *rtv1);
void						event_mouse(t_rt *rtv1);
void						event_mouse(t_rt *rtv1);
void						event_moove_up(t_rt *rtv1);
void						event_moove_down(t_rt *rtv1);
void						event_add_obj(t_rt *rtv1);
void						add_torus(t_rt *rtv1);
void						add_triangle(t_rt *rtv1);
void						add_plan(t_rt *rtv1);
void						add_sphere(t_rt *rtv1);
void						add_light(t_rt *rtv1);
void						add_alter(t_rt *rtv1);
void						event_change_rgb(t_rt *rtv1);
void						event_screenshot(t_rt *rtv1, int i);
void						event_effect(t_rt *rtv1);
void						event_cam_ori(t_rt *rtv1);
void						event_affichagedumal(t_rt *rtv1);
void						del_object(t_rt *rtv1);
void						event_obj2(t_rt *rtv1);
void						event_obj(t_rt *rtv1);
void						event_change_scene2(t_rt *rtv1);
void						event_change_scene(t_rt *rtv1);
void						set_object_info(t_object *tmp, t_rt *rtv1);
void						set_ray_add(t_rt *rtv1);
void						free_list(t_object *list);
int							cylinder_hit(t_camera *cam, t_object *cy, float *t);
int							cone_hit(t_camera *cam, t_object *cone, float *t);
int							plan_hit(t_camera *cam, t_object *p, float *t);
int							sphere_hit(t_camera *cam, t_object *s, float *t);
int							torus_hit(t_camera *cam, t_object *s, float *t);
int							triangle_hit(t_camera *cam, t_object *tle,\
											float *t);
void						triangle_tape(t_camera *camera, t_object *obj,\
											float *tnear, t_object **hitobject);
void						torus_tape(t_camera *camera, t_object *obj,\
										float *tnear, t_object **hitobject);
void						cylinder_tape(t_camera *camera, t_object *obj,\
											float *tnear, t_object **hitobject);
void						plan_tape(t_camera *camera, t_object *obj,\
										float *tnear, t_object **hitobject);
void						sphere_tape(t_camera *camera, t_object *obj,\
										float *tnear, t_object **hitobject);
void						cone_tape(t_camera *camera, t_object *obj,\
										float *tnear, t_object **hitobject);
int							cl_read_buffer(t_rt *rtv1, t_kernel *kernel,\
											t_cl_buffer *cl_b, size_t *giz);
int							cl_erreur_log(t_cl *cl, cl_int error);
int							cl_create_platform(t_cl *cl);
int							cl_create_program(t_cl *cl, const char\
											*file_buffer, size_t source_size);
int							cl_create_kernel(t_rt *rtv1, t_kernel *kernel,\
												t_cl_buffer *cl_b);
int							cl_create_buffer(t_rt *rtv1, t_cl_buffer *cl_b);
void						ft_moove(t_rt *rtv1);
void						get_rgb_from_int(int col, t_color *color);
void						fsdl_draw_pt(SDL_Surface *dst, size_t clr,\
											int x, int y);
int							trace(t_camera *camera, t_object *obj,\
								t_object **hitobject, float *tnear);
int							calc_light(t_rt *rtv1, t_object *object);
int							draw_rt(t_rt *rtv1);
void						event_rt(t_rt *rtv1);
int							del_list_event(void *data, SDL_Event *event);
void						rotate_x(t_rt *rtv1);
void						rotate_y(t_rt *rtv1);
void						rotate_z(t_rt *rtv1);
int							init_param(t_rt *rtv1);
int							parse_object(t_rt *rtv1, char *object);
int							init_param(t_rt *rtv1);
void						creat_perm(t_rt *rtv1);
void						cpy_texture2(SDL_Surface	*tex, int *a,\
											int *b, int *c);
int							init_texture(t_rt *rtv1);
int							init_opencl(t_rt *rt);
void						interface(t_rt *rtv1);

#endif
