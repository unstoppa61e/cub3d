/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:12:23 by monoue            #+#    #+#             */
/*   Updated: 2020/11/25 12:26:22 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BACKGROUND_H
# define RENDER_BACKGROUND_H

# include "../../defs.h"
# include "../../global/init_g_player.h"
# include "../../global/init_g_color.h"
# include "../../global/init_g_distance_proj_plane.h"
# include "../../global/init_g_rays.h"
# include "render_wall_ray_basis.h"
# include "draw_pixel.h"

void	render_background(void);
int		calc_projected_object_height(float angle_to_object,
													float distance_to_object);

#endif
