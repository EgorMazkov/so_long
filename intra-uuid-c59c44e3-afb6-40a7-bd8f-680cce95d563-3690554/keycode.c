#include "so_long.h"

void	keycode_number(int keycode, t_data *image, int x, int z)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 1)
		keycode_s(keycode, image, x, z);
	else if (keycode == 0)
		keycode_a(keycode, image, x, z);
	else if (keycode == 2)
		keycode_d(keycode, image, x, z);
	else if (keycode == 13)
		keycode_w(keycode, image, x, z);
	free(image->str);
	image->str = ft_itoa(image->descent_counter);
	if (image->steps)
	{
		mlx_string_put(image->mlx, image->mlx_win, 30, 40, 0xffffff, "Steps");
		image->steps = 0;
	}
	mlx_string_put(image->mlx, image->mlx_win, 79, 39, 0x000000, image->str);
	mlx_string_put(image->mlx, image->mlx_win, 81, 41, 0x000000, image->str);
	mlx_string_put(image->mlx, image->mlx_win, 80, 40, 0xffffff, image->str);
}

void	keycode_s(int keycode, t_data *image, int x, int z)
{
	if (keycode == 1)
	{
		concludesion_case1(2, image, x, z);
		if (x > image->b - 3)
		{
			image->descent_counter--;
			x = image->b - 2;
		}
		else
			x++;
		wasd_proverka(image, x, z, 1);
		if (image->mass[x][z] != '1')
			concludesion_case1(5, image, x, z);
	}
}

void	keycode_a(int keycode, t_data *image, int x, int z)
{
	if (keycode == 0)
	{
		concludesion_case1(2, image, x, z);
		if (z <= 1)
		{
			image->descent_counter--;
			z = 1;
		}
		else
			z--;
		wasd_proverka(image, x, z, 0);
		if (image->mass[x][z] != '1')
			concludesion_case1(9, image, x, z);
	}
}

void	keycode_d(int keycode, t_data *image, int x, int z)
{
	if (keycode == 2)
	{
		concludesion_case1(2, image, x, z);
		if (z < image->width - 3)
			z++;
		else
		{
			image->descent_counter--;
			z = image->width - 2;
		}
		wasd_proverka(image, x, z, 2);
		if (image->mass[x][z] != '1')
			concludesion_case1(8, image, x, z);
	}
}

void	keycode_w(int keycode, t_data *image, int x, int z)
{
	if (keycode == 13)
	{
		concludesion_case1(2, image, x, z);
		if (x <= 1)
		{
			image->descent_counter--;
			x = 1;
		}
		else
			x--;
		wasd_proverka(image, x, z, 13);
		if (image->mass[x][z] != '1')
			concludesion_case1(7, image, x, z);
	}
}
