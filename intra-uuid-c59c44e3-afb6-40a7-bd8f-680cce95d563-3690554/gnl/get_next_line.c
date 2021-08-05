#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (a);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (NULL);
	ft_memset(new, 0, count * size);
	return (new);
}

static char	*check_pnt(char **variable, char **line)
{
	char	*pnt;

	pnt = NULL;
	if (*variable)
	{
		pnt = (ft_strchr(*variable, '\n'));
		if (pnt)
		{
			*pnt = '\0';
			*line = ft_strdup(*variable);
			ft_strcpy(*variable, ++pnt);
		}
		else
		{
			*line = ft_strdup(*variable);
			free(*variable);
			*variable = NULL;
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (pnt);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	char		*pnt;
	static char	*variable;
	int			text;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	text = 1;
	pnt = check_pnt(&variable, line);
	while (!pnt && text > 0)
	{
		text = read(fd, buff, BUFFER_SIZE);
		buff[text] = '\0';
		pnt = ft_strchr(buff, '\n');
		if (pnt)
		{
			*pnt = '\0';
			variable = ft_strdup(++pnt);
		}
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	return (variable && text);
}
