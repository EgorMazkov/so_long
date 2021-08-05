#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx_opengl_20191021/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	char	**mass;
	char	*str;
	char	*line;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		b;
	int		width;
	int		item;
	int		descent_counter;
	int		a;
	int		exit_j;
	int		exit_i;
	int		flags;
	int		steps;
	int		p;
	int		e;
	int		fd;
	int		flag;
	int		x;
	int		z;

}	t_data;

typedef struct s_img
{
	void	*wall;
	void	*emp;
	void	*item;
	void	*exit;
	void	*down;
	void	*up;
	void	*left;
	void	*right;
	void	*enemy;
	int		w;
	int		h;
}	t_img;

typedef struct s_type
{
	int		a;
	int		o;
	int		c;
	int		e;
	int		p;
}	t_type;

void	casechecking_horizontal_walls(t_data *image);
void	checking_vertical_walls(t_data *image);
void	checing_element(t_data *image);
void	error(void);
void	concludesion(t_data *image);
void	keycode_s_x_minus(t_data *image, int x, int z);
void	keycode_a_z_plus(t_data *image, int x, int z);
void	keycode_d_z_minus(t_data *image, int x, int z);
void	keycode_w_x_plus(t_data *image, int x, int z);
void	concludesion_case1(int a, t_data *mpx, int i, int j);
void	flags(t_data *image, int x, int z);
void	wasd_proverka(t_data *image, int x, int z, int a);
void	null(t_data *image);
void	keycode_s(int keycode, t_data *image, int x, int z);
void	proverka_C_E(t_data *image, int x, int z);
void	proverka_1(t_data *image, int x, int z);
void	keycode_a(int keycode, t_data *image, int x, int z);
void	keycode_d(int keycode, t_data *image, int x, int z);
void	keycode_w(int keycode, t_data *image, int x, int z);
void	keycode_number(int keycode, t_data *image, int x, int z);
void	exit_E(t_data *image, int x, int z);
void	key_code_wasd(t_data *image, int x, int y);
void	you_lose(void);
void	b_width(t_data *image, char **argv);
void	malloc_b_width(t_data *image);
void	casechecking_horizontal_walls_case2(t_data *image);
void	checing_element_case_one(t_data *image);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		key_hook(int keycode, t_data *image);
int		mlx_close(t_data *image);
#endif