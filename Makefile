NAME = cub3D
CC = gcc

SRCS =
OBJS =		$(SRCS:%.c=%.o)
CLIBS =		-L . -lft
CFLAGS =	-Wall -Wextra -Werror

SRCS += src/coord.c
SRCS += src/create_maps.c
SRCS += src/draw_shape.c
SRCS += src/error.c
SRCS += src/event_hook.c
SRCS += src/get_line_data_utils.c
SRCS += src/graphics.c
SRCS += src/init_mlx.c
SRCS += src/is_map_line.c
SRCS += src/main.c
SRCS += src/map_check.c
SRCS += src/map_error.c
SRCS += src/player.c
SRCS += src/ray.c
SRCS += src/render_sprites.c
SRCS += src/render_mini_map.c
SRCS += src/render_wall_ray_basis.c
SRCS += src/save_image.c
SRCS += src/set_color.c
SRCS += src/set_cubfile_data.c
# SRCS += src/texture.c
SRCS += src/wall.c
SRCS += src/write_image.c
SRCS += src/sprite.c

SRCS += src/test.c

$(NAME): $(OBJS)
	gcc -g -fsanitize=address $(SRCS) ./libft.a ./libmlx.dylib -o cub3D;
	# gcc -g -fsanitize=address $(SRCS) ./libft.a -o cub3D;
	# ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	./cub3D test_map/1.cub

.PHONY: all clean fclean re run
