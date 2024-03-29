/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:49:30 by monoue            #+#    #+#             */
/*   Updated: 2020/12/09 16:46:15 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "defs_bonus.h"
#include "error_exit/error_exit_bonus.h"
#include "game_loop/game_loop_bonus.h"
#include "global/init_g_img_bonus.h"
#include "global/init_g_save_flag_bonus.h"
#include "global/init_g_textures_bonus.h"
#include "../libft/libft.h"
#include "set_config/malloc_rays_wall_hit_coord_bonus.h"
#include "set_config/set_config_bonus.h"
#include "game_loop/event_hook_bonus.h"

static void	set_textures(void)
{
	size_t		t_i;

	t_i = 0;
	while (t_i < TEXTURES_NUM)
	{
		g_textures[t_i].img_ptr = mlx_xpm_file_to_image(
			g_mlx.mlx_ptr,
			g_textures[t_i].path,
			&g_textures[t_i].width,
			&g_textures[t_i].height);
		if (g_textures[t_i].img_ptr == NULL)
			exit_with_error_message(ERRNO, NULL);
		g_textures[t_i].addr = mlx_get_data_addr(
			g_textures[t_i].img_ptr,
			&g_textures[t_i].bits_per_pixel,
			&g_textures[t_i].line_length,
			&g_textures[t_i].endian);
		t_i++;
	}
}

static void	init_mlx(void)
{
	g_mlx.mlx_ptr = mlx_init();
	g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, g_config.window_width,
								g_config.window_height, TITLE);
	g_img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_config.window_width,
												g_config.window_height);
	g_img.addr = mlx_get_data_addr(g_img.img_ptr, &g_img.bits_per_pixel,
											&g_img.line_length, &g_img.endian);
	set_textures();
}

static void	play_the_game(char *filename)
{
	set_config(filename);
	malloc_rays_wall_hit_coord();
	init_mlx();
	event_hook();
	mlx_loop_hook(g_mlx.mlx_ptr, &game_loop, NULL);
	mlx_loop(g_mlx.mlx_ptr);
}

static bool	extension_is_invalid(char *arg1, const size_t extension_len)
{
	const size_t	extension_start_index = ft_strlen(arg1) - extension_len;
	const char		*extension = &arg1[extension_start_index];

	return (!(ft_strcmp(extension, EXTENSION) == 0));
}

int			main(int argc, char **argv)
{
	const size_t	extension_len = ft_strlen(EXTENSION);

	if (argc < 2)
		exit_with_error_message(SINGLE, NO_ARG);
	if (argc > 3)
		exit_with_error_message(SINGLE, strerror(E2BIG));
	if (ft_strlen(argv[1]) < extension_len
		|| extension_is_invalid(argv[1], extension_len))
	{
		exit_with_error_message(SINGLE, strerror(EINVAL));
	}
	if (argc == NO_OPTION)
		play_the_game(argv[1]);
	else
	{
		if (ft_strcmp(argv[2], SAVE_OPTION) != 0)
			exit_with_error_message(SINGLE, strerror(EINVAL));
		g_save_flag = true;
		play_the_game(argv[1]);
	}
}
