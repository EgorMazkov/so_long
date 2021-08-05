#include "so_long.h"

static void	concludesion_case2(t_img *img)
{
	img->wall = "img/wall.xpm";
	img->emp = "img/emptiness.xpm";
	img->item = "img/item.xpm";
	img->exit = "img/exit.xpm";
	img->down = "img/down.xpm";
	img->up = "img/up.xpm";
	img->left = "img/left.xpm";
	img->right = "img/right.xpm";
	img->enemy = "img/enemy.xpm";
}

void	concludesion_case1(int a, t_data *mpx, int i, int j)
{
	t_img	img;
	void	*image;

	concludesion_case2(&img);
	if (a == 1)
		image = mlx_xpm_file_to_image(mpx->mlx, img.wall, &img.w, &img.h);
	else if (a == 2)
		image = mlx_xpm_file_to_image(mpx->mlx, img.emp, &img.w, &img.h);
	else if (a == 3)
		image = mlx_xpm_file_to_image(mpx->mlx, img.item, &img.w, &img.h);
	else if (a == 4)
		image = mlx_xpm_file_to_image(mpx->mlx, img.exit, &img.w, &img.h);
	else if (a == 5)
		image = mlx_xpm_file_to_image(mpx->mlx, img.down, &img.w, &img.h);
	else if (a == 6)
		image = mlx_xpm_file_to_image(mpx->mlx, img.enemy, &img.w, &img.h);
	else if (a == 7)
		image = mlx_xpm_file_to_image(mpx->mlx, img.up, &img.w, &img.h);
	else if (a == 8)
		image = mlx_xpm_file_to_image(mpx->mlx, img.right, &img.w, &img.h);
	else
		image = mlx_xpm_file_to_image(mpx->mlx, img.left, &img.w, &img.h);
	mlx_put_image_to_window(mpx->mlx, mpx->mlx_win, image, 64 * j, 64 * i + 64);
}

void	concludesion(t_data *image)
{
	int	i;
	int	j;

	i = 0;
	while (image->mass[i])
	{
		j = 0;
		while (image->mass[i][j])
		{
			if (image->mass[i][j] == '1')
				concludesion_case1(1, image, i, j);
			else if (image->mass[i][j] == '0')
				concludesion_case1(2, image, i, j);
			else if (image->mass[i][j] == 'C')
				concludesion_case1(3, image, i, j);
			else if (image->mass[i][j] == 'E')
				concludesion_case1(4, image, i, j);
			else if (image->mass[i][j] == 'P')
				concludesion_case1(5, image, i, j);
			else if (image->mass[i][j] == 'X')
				concludesion_case1(6, image, i, j);
			j++;
		}
		i++;
	}
}

int	mlx_close(t_data *image)
{
	mlx_destroy_window(image->mlx, image->mlx_win);
	exit(0);
	return (0);
}
