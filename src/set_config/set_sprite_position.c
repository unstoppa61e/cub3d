/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:04:28 by monoue            #+#    #+#             */
/*   Updated: 2020/11/25 11:37:07 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_sprite_position.h"

void		set_sprite_position(size_t x, size_t y, size_t sprite_i)
{
	g_sprites[sprite_i].x = x * TILE_SIZE + TILE_SIZE * 0.5;
	g_sprites[sprite_i].y = y * TILE_SIZE + TILE_SIZE * 0.5;
}
