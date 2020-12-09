/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:10:13 by monoue            #+#    #+#             */
/*   Updated: 2020/12/09 16:46:15 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAPS_H
# define CREATE_MAPS_H

# include "../../libft/libft.h"
# include "../defs_bonus.h"
# include "../error_exit/error_exit_bonus.h"
# include "../global/init_g_map_bonus.h"
# include "../global/init_g_map_to_check_bonus.h"

void	create_map_array(char *map_first_line, int fd);
void	init_maps(void);

#endif
