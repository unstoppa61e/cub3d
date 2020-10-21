#ifndef GRAPHICS_H

# define GRAPHICS_H

# include <stdint.h>
# include <stdbool.h>
# include "defs.h"
# include <SDL2/SDL.h>
// # include </Users/monoue/homebrew/include/SDL2/SDL.h>

bool	initialize_window(void);
void	destroy_window(void);
void	clear_color_buffer(t_color color);
void	render_color_buffer(void);
void	draw_pixel(int x, int y, uint32_t color);
void	draw_rect(int x, int y, int width, int height, uint32_t color);
void	draw_line(int x0, int y0, int x1, int y1, uint32_t color);

#endif