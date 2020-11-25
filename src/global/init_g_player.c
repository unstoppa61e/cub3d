/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:09:49 by monoue            #+#    #+#             */
/*   Updated: 2020/11/25 10:10:04 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/global/init_g_player.h"

t_player		g_player =
{
	.x = NOT_SET,
	.y = NOT_SET,
	.width = 5,
	.height = 5,
	.turn_direction = NEUTRAL,
	.walk_direction = NEUTRAL,
	.walk_speed = 80,
	.turn_speed = 3 * (PI / 180)
};