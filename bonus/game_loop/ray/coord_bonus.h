/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:07:48 by monoue            #+#    #+#             */
/*   Updated: 2020/12/10 07:19:11 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_BONUS_H
# define COORD_BONUS_H

typedef struct	s_coord {
	float	x;
	float	y;
}				t_coord;

t_coord			*coord_assign(t_coord *dst, float x, float y);
t_coord			*coord_copy(t_coord *dst, t_coord *src);
t_coord			*coord_add(t_coord *dst, t_coord *add);

#endif
