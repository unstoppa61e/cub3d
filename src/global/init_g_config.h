/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:22:39 by monoue            #+#    #+#             */
/*   Updated: 2020/12/01 12:22:42 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_G_CONFIG_H
# define INIT_G_CONFIG_H

# include "../defs.h"

typedef struct	s_config
{
	int			window_width;
	int			window_height;
	t_color		floor_color;
	t_color		ceiling_color;
	size_t		sprites_num;
}				t_config;

extern t_config g_config;

#endif
