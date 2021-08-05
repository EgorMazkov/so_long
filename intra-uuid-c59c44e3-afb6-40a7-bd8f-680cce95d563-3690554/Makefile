NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

SRCS	= so_long.c  parser.c conclusion.c keycode.c key_code_case_one.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			key_code_case_two.c so_long_case_one.c ft_itoa.c wasd_proverka.c

$(NAME):
	$(CC) -g $(CFLAGS) -I ./gnl/ -I ./minilibx_opengl_20191021/ -framework OpenGL -framework AppKit -lmlx minilibx_opengl_20191021/libmlx.a $(SRCS) -o $(NAME)

all: $(NAME)

norm:
	norminette *c

clean:
	@/bin/rm -rf so_long.dSYM

fclean:
	@/bin/rm -f $(NAME)

re: fclean all