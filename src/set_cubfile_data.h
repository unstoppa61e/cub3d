/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cubfile_data.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:11:56 by monoue            #+#    #+#             */
/*   Updated: 2020/11/24 13:04:16 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_CUBFILE_DATA_H
# define SET_CUBFILE_DATA_H

# include <fcntl.h>

# include "create_maps.h"
# include "get_line_data_utils.h"
# include "init_mlx.h"
# include "is_map_line.h"
# include "libft/libft.h"
# include "map_error.h"
# include "player.h"
# include "set_color.h"
# include "sprite.h"

void	set_cubfile_data(char *filename);

#endif
