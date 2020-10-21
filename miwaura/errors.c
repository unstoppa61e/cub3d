/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:42:30 by miwaura           #+#    #+#             */
/*   Updated: 2020/10/14 14:05:38 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_err_msg(char *s)
{
	int i;

	write(1, "Error\n", 6);
	i = (int)ft_strlen(s);
	write(1, s, i);
	return (1);
}

void	exit_failure_closing_fd(char *s, int fd)
{
	put_err_msg(s);
	close(fd);
	exit(0);
}

void	error_map(char *s, char *line, char *map)
{
	put_err_msg(s);
	free(line);
	free(map);
	exit(0);
}