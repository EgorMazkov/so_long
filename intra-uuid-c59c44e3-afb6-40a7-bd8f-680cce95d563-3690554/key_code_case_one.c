#include "so_long.h"

void	exit_E(t_data *image, int x, int z)
{
	if (image->mass[x][z] == 'E')
	{
		if (image->item == 0)
		{
			printf("%s\n", "You Win!");
			exit(0);
		}
	}
}

void	proverka_C_E(t_data *image, int x, int z)
{
	if (image->mass[x][z] == 'C')
		image->item--;
}

void	proverka_1(t_data *image, int x, int z)
{
	if (image->mass[x][z] != '1')
	{
		image->descent_counter++;
		proverka_C_E(image, x, z);
		image->mass[x][z] = 'P';
	}
}

void	you_lose(void)
{
	printf("%s\n", "You Lose!");
	exit(0);
}

void	key_code_wasd(t_data *image, int x, int z)
{
	if (image->mass[x][z] == 'E')
	{
		image->flags = 1;
		image->mass[x][z] = 'E';
		exit_E(image, x, z);
		image->mass[x][z] = 'P';
		concludesion_case1(5, image, x, z);
		image->descent_counter++;
	}
}
