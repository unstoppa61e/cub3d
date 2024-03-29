/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:18:43 by monoue            #+#    #+#             */
/*   Updated: 2020/11/27 10:31:45 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_texture_color.h"

void			set_texture_color(t_texture texture, int x, int y)
{
	char	*pixel_color;

	pixel_color = texture.addr
				+ (y * texture.line_length + x * (texture.bits_per_pixel / 8));
	g_color = (*(unsigned int*)pixel_color);
}
