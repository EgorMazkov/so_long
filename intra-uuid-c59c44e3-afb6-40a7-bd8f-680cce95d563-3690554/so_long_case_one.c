#include "so_long.h"

void	error(void)
{
	printf("%s\n", "Error");
	exit(1);
}

void	b_width(t_data *image, char **argv)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	while (get_next_line(fd, &image->line))
	{
		image->b++;
		if (image->flag)
		{
			image->width = ft_strlen(image->line);
			image->flag = 0;
		}
		image->a = ft_strlen(image->line);
		if (image->a != image->width)
			error();
		free(image->line);
	}
	free(image->line);
	image->line = NULL;
	close(fd);
}

void	malloc_b_width(t_data *image)
{
	int	i;

	i = 0;
	image->mass = (char **)malloc(sizeof(char *) * ((image->b + 1)));
	if (!image->mass)
		exit(1);
	while (i < image->b)
	{
		image->mass[i] = (char *)malloc(sizeof(char) * (image->width));
		if (!image->mass)
			exit(1);
		image->mass[i][image->width] = '\0';
		i++;
	}
	image->mass[image->b] = NULL;
}
