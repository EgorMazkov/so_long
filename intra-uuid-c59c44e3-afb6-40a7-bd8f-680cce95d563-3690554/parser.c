#include "so_long.h"

void	casechecking_horizontal_walls_case2(t_data *image)
{
	int	i;
	int	j;
	int	a;

	j = 0;
	a = 0;
	i = image->b - 1;
	while (image->mass[i][j] && j != image->width)
	{
		if (image->mass[i][j] == '1')
			j++;
		else
			error();
	}
}

void	casechecking_horizontal_walls(t_data *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (image->mass[i][j] && j != image->width)
	{
		if (image->mass[i][j] == '1')
			j++;
		else
			error();
	}
	j = 0;
	while (image->mass[i][j] && j != image->width)
	{
		if (image->mass[i][j] == '1')
			j++;
	}
	image->mlx_win = mlx_new_window(image->mlx, j * 64, \
	(image->b) * 64 + 64, "so_long");
	if ((image->b - 1) == j)
		error();
	casechecking_horizontal_walls_case2(image);
}

void	checking_vertical_walls(t_data *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != image->b - 1)
	{
		if (image->mass[i][j] != '1')
			error();
		if (image->mass[i][image->width - 1] != '1')
			error();
		i++;
	}
}

void	checing_element(t_data *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (image->mass[i] && i != image->b - 1)
	{
		while (image->mass[i][j] && j != image->width)
		{
			if (image->mass[i][j] == 'P')
				image->p++;
			else if (image->mass[i][j] == 'C')
				image->item++;
			else if (image->mass[i][j] == 'E')
			{
				image->exit_j = j;
				image->exit_i = i;
				image->e++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	checing_element_case_one(image);
}

void	checing_element_case_one(t_data *image)
{
	if (image->p != 1 || image->e != 1 || image->item <= 0)
		error();
}
