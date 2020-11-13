#ifndef MAP_CHECK_H
# define MAP_CHECK_H

# include "create_maps.h"
# include "defs.h"
# include "init_mlx.h"
# include "map_error.h"

bool	map_has_target_at(float x, float y, char c);
bool	map_has_sprite_at(float x, float y);
bool	map_has_wall_at(float x, float y);
bool	is_space_at(const float pixel_x, const float pixel_y);

#endif