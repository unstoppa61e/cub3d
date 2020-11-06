#ifndef INIT_MLX_H
# define INIT_MLX_H

# include "defs.h"
# include "set_cubfile_data.h"
# include "player.h"
# include "set_color.h"
# include "texture.h"
# include "graphics.h"
# include "ray.h"
# include "event_hook.h"
# include "wall.h"
# include "../minilibx/mlx.h"




typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

extern	t_mlx g_mlx;
extern	t_img g_img;
extern	t_color	*wall_texture;

void	mlx(void);
void	init_texture_paths();
bool	map_has_wall_at(float x, float y);
bool	is_out_of_window(float x, float y);

#endif
