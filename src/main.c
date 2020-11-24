/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:49:30 by monoue            #+#    #+#             */
/*   Updated: 2020/11/24 16:30:39 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "map_error.h"
#include "create_maps.h"
#include "defs.h"
#include "error.h"
#include "init_mlx.h"
#include "libft/libft.h"
#include "debug.h"
#include "../minilibx/mlx.h"
#include "player.h"
#include "set_cubfile_data.h"

void	play_the_game(char *filename)
{
	set_cubfile_data(filename);
	mlx();
}

int	main(int argc, char **argv)
{
	const char	*extension = ".cub";
	const char	*option = "--save";

	if (argc < 2)
		exit_with_error_message(SINGLE, "No arguments");
	if (argc > 3)
		exit_with_error_message(SINGLE, strerror(E2BIG));
	// TODO: 以下の２つはエラーパターンが同じなので、まとめる
	if (ft_strlen(argv[1]) < 5 || ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], extension) != 0)
		exit_with_error_message(SINGLE, strerror(EINVAL));
	if (argc == 2)
		play_the_game(argv[1]);
	else
	{
		if (ft_strcmp(argv[2], option) != 0)
			exit_with_error_message(SINGLE, strerror(EINVAL));
		// TODO: save_picture(argv[1]);
	}
}
