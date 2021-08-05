#include "so_long.h"

void	flags(t_data *image, int x, int z)
{
	if (image->flags == 1)
	{
		concludesion_case1(4, image, image->exit_i, image->exit_j);
		image->mass[image->exit_i][image->exit_j] = 'E';
		if (image->item == 0)
			exit_E(image, x, z);
		else
			image->flags = 1;
	}
}
