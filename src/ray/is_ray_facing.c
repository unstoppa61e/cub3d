/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_facing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:09:50 by monoue            #+#    #+#             */
/*   Updated: 2020/11/24 16:27:52 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_ray_facing.h"

bool	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

bool	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

bool	is_ray_facing_right(float angle)
{
	return (angle < HALF_PI || angle > PI + HALF_PI);
}

bool	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
