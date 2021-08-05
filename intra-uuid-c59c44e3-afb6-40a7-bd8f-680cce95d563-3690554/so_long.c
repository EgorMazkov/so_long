#include "so_long.h"

static	void	fill_mass(t_data *image, char **argv)
{
	int		i;
	int		j;
	int		fd;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	while (get_next_line(fd, &image->line))
	{
		i = 0;
		while (image->line[i] && i != image->width)
		{
			image->mass[j][i] = image->line[i];
			i++;
		}
		j++;
		free(image->line);
	}
	close(fd);
}

static	int	key_code(int keycode, t_data *image)
{
	int	i;
	int	j;

	if (!(keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13 \
	|| keycode == 53))
		return (0);
	i = 0;
	while (image->mass[i])
	{
		j = 0;
		while (image->mass[i][j])
		{
			if (image->mass[i][j] == 'P')
			{
				image->x = i;
				image->z = j;
				image->mass[i][j] = '0';
				break ;
			}
			j++;
		}
		i++;
	}
	keycode_number(keycode, image, image->x, image->z);
	return (0);
}

void	null(t_data *image)
{
	image->b = 0;
	image->width = 0;
	image->item = 0;
	image->descent_counter = 0;
	image->str = ft_strdup("");
	image->exit_i = 0;
	image->exit_j = 0;
	image->flags = 0;
	image->steps = 1;
	image->p = 0;
	image->e = 0;
	image->line = NULL;
	image->flag = 1;
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	image;

	(void)argc;
	i = 0;
	null(&image);
	image.mlx = mlx_init();
	b_width(&image, argv);
	malloc_b_width(&image);
	fill_mass(&image, argv);
	casechecking_horizontal_walls(&image);
	checking_vertical_walls(&image);
	checing_element(&image);
	concludesion(&image);
	image.img = mlx_new_image(image.mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
	&image.line_length, &image.endian);
	mlx_hook(image.mlx_win, 17, 1L << 17, &mlx_close, &image);
	mlx_key_hook(image.mlx_win, key_code, &image);
	mlx_loop(image.mlx);
	free(image.str);
}
