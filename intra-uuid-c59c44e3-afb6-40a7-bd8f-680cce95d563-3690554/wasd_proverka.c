#include "so_long.h"

void	wasd_proverka(t_data *image, int x, int z, int a)
{
	if (image->mass[x][z] == '1')
	{
		if (a == 1)
			keycode_s_x_minus(image, x, z);
		else if (a == 0)
			keycode_a_z_plus(image, x, z);
		else if (a == 2)
			keycode_d_z_minus(image, x, z);
		else if (a == 13)
			keycode_w_x_plus(image, x, z);
		concludesion_case1(1, image, x, z);
	}
	else if (image->flags == 1)
		flags(image, x, z);
	if (image->mass[x][z] != '1' &&
		image->mass[x][z] != 'E' && image->mass[x][z] != 'X')
		proverka_1(image, x, z);
	else if (image->mass[x][z] == 'E')
		key_code_wasd(image, x, z);
	else if (image->mass[x][z] == 'X')
		you_lose();
}

void	keycode_s_x_minus(t_data *image, int x, int z)
{
	x--;
	image->mass[x][z] = 'P';
	concludesion_case1(5, image, x, z);
}

void	keycode_a_z_plus(t_data *image, int x, int z)
{
	z++;
	image->mass[x][z] = 'P';
	concludesion_case1(9, image, x, z);
}

void	keycode_d_z_minus(t_data *image, int x, int z)
{
	z--;
	image->mass[x][z] = 'P';
	concludesion_case1(8, image, x, z);
}

void	keycode_w_x_plus(t_data *image, int x, int z)
{
	x++;
	image->mass[x][z] = 'P';
	concludesion_case1(7, image, x, z);
}
