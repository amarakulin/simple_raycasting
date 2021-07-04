
#ifndef CUB3D_H
# define CUB3D_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**map;
	size_t		h_map;
	size_t		len_map;
	size_t		nbr_sp;
	size_t		nl;

}				t_map;

typedef struct	s_param
{
	t_list		*lst_param;
	int			h;
	int			w;
	size_t		color_floor;
	size_t		color_ceiling;
	char		*paths[5];
}				t_param;

typedef struct	s_win
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bit_pp;
	int			l_len;
	int			en;

}				t_win;

typedef struct	s_hero
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		rotate;
}				t_hero;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dis;
}				t_sprite;

typedef struct	s_w_cas
{
	double		camera_y;
	double		ray_dir_y;
	double		ray_dir_x;
	int			map_x;
	int			map_y;
	double		side_dist_y;
	double		side_dist_x;
	double		delta_dist_y;
	double		delta_dist_x;
	double		perp_wall_dist;
	int			step_y;
	int			step_x;
	double		wall_x;
	int			side;
	int			line_h;
	int			draw_start_wall;
	int			draw_end_wall;
	double		*z_buff;
}				t_w_cas;

typedef struct	s_texture
{
	void		*img;
	char		*addr;
	int			bit_pp;
	int			l_len;
	int			en;
	int			h;
	int			w;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			*arr_textr;
}				t_texture;

typedef struct	s_sp_cas
{
	double		sp_x;
	double		sp_y;
	double		inv_det;
	double		transf_x;
	double		transf_y;
	int			sp_screen_x;
	int			sp_h;
	int			sp_w;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
}				t_sp_cas;

typedef struct	s_data
{
	t_map		map;
	t_win		win;
	t_hero		hero;
	t_sprite	*sprite;
	t_w_cas		wall_cast;
	t_texture	*textr;
	t_sp_cas	sprite_cast;
	t_param		param;
}				t_data;

/*
** parser.c
*/

void			parsing(int argc, char **argv, t_data **data);

/*
** parser.c
*/

int				read_file(int fd, t_data *data);
char			*addback_space_to_str(char *str, t_data	*data);
int				convert_lst_to_arr(t_list *head, t_data *data);
char			*create_lst_param(int fd, t_data *data);
char			*check_arg(char *line);

/*
** validate_map.c
*/

int				validate_map(t_data *data);
int				check_space(size_t x, size_t y, t_data *data);
int				validate_border_symbols(size_t x, size_t y, t_data *data);
int				validate_inner_symbols(size_t x, size_t y, t_data *data);

/*
** validate_param.c
*/

int				validate_param(t_data *data);
int				choose_param_validate(char *str);
char			*skip_spaces(char *str, size_t index);
int				count_len_int(int nbr, char *str);
int				validate_arg(char *str);

/*
** init_data.c
*/

int				init_data(t_data *data);
void			coordinate_sprite(size_t x, size_t y, t_data *data, int i);
void			init_window(t_data *data);
void			read_map(t_data *data);

/*
** utils_init.c
*/

void			init_hero_n_s(size_t x, size_t y, t_data *data);
void			init_hero_w_e(size_t x, size_t y, t_data *data);
void			init_floor_celling(char *str, char param, t_data *data);
void			init_path(char *str, char param, t_data *data);
unsigned int	create_trgb(int r, int g, int b);

/*
** run_window.c
*/

void			run_window(t_data *data);
int				buttons(int keycode, t_data *data);

/*
** print_out.c
*/

void			print_map_on_window(t_data *data);
void			fast_mlx_pixel_put(size_t x, size_t y, t_data *data,
									unsigned int color);
unsigned int	get_color_pixel(int x, int y, t_texture texture);

/*
** wall_casting.c
*/

void			wall_casting(t_data *data);
void			get_start_end_walls(t_w_cas *vars, t_data *data);
void			get_data_when_ray_hit_walls(t_w_cas *vars, t_data *data);
void			set_side_dist_and_step(t_w_cas *vars, t_data *data);
void			init_vars(int x, t_w_cas *vars, t_data *data);

/*
** sprite_casting.c
*/

void			sprite_casting(t_data *data);
void			get_data_for_sprite(int i, t_sp_cas *vars, t_data *data);
void			get_dist_from_hero_to_sprites(t_data *data);

/*
** texture_calculation.c
*/

void			get_data_texture(t_texture *texture, t_w_cas *vars,
								t_data *data);
void			texture_calculation(int x, t_w_cas *vars, t_data *data);

/*
** load_img.c
*/

int				load_img(t_data *data);
void			fill_texture(int i, t_data *data);

/*
** buttons.c
*/

void			move_up_down(int keycode, t_data *data);
void			move_left_right(int keycode, t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
int				close_win(t_data *data);

/*
** sort_decreasing.c
*/

void			swap_sprites(int i, int j, t_data *data);
int				partition(int low, int high, t_data *data);
void			sort_decreasing_sprites(int low, int high, t_data *data);

/*
** utils_clean_error.c
*/

void			print_out_errors(int error);
void			del(void *str);

/*
** screen_save.c
*/

int				create_screenshot(t_data *data);
int				validate_save_arg(char *save_arg);

#endif
