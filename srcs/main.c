/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:10:10 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/22 11:10:11 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot			*dot_init(int x, int y, int altitude, int color)
{
	t_dot		*dot;

	dot = (t_dot*)malloc(sizeof(t_dot));
	dot->x = (double)x;
	dot->y = (double)y;
	dot->altitude = (double)altitude;
	dot->next = NULL;
	dot->prev = NULL;
	dot->color = color;
	if (dot->altitude > 0)
		dot->color = GREEN;
	if (dot->altitude < 0)
		dot->color = RED;
	return (dot);
}

t_dot			*add_dot(t_dot *rebro_to_end, t_dot *begin)
{
	t_dot		*begin_copy;

	begin_copy = begin;
	if (!begin)
		begin_copy = rebro_to_end;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = rebro_to_end;
		rebro_to_end->prev = begin;
	}
	return (rebro_to_end);
}

void			fill_dots(t_dot **dot, t_map_info *m_i)
{
	int			i;
	int			j;
	t_dot		*dot_end;

	i = -1;
	j = -1;
	*dot = NULL;
	dot_end = NULL;
	while (m_i->map_int[++i])
	{
		j = -1;
		while (++j < m_i->width)
		{
			dot_end = add_dot(dot_init(j, i, m_i->map_int[i][j],\
				(m_i->color)), dot_end);
		}
	}
	while (dot_end->prev)
		dot_end = dot_end->prev;
	*dot = dot_end;
}

void			map_info_init(t_map_info *map_info)
{
	map_info->depth = -3;
	map_info->zoom = 17;
	if (map_info->width > 45 || map_info->height > 45)
		map_info->zoom = 2;
	if (map_info->width >= 100 || map_info->height >= 100)
		map_info->zoom = 0.0001;
	map_info->d_width = 1;
	map_info->d_height = 2;
	map_info->x_move = WIDTH / 2;
	map_info->y_move = HEIGHT / 2;
	map_info->x_rot = 0;
}

int				main(int argv, char **argc)
{
	t_map_info	map_info;
	t_dot		*dot;

	if (argv != 2)
	{
		write(1, "Usage : ./fdf [filename]\n",\
		ft_strlen("Usage : ./fdf [filename]\n"));
		return (0);
	}
	file_read_and_fill(&map_info, argc[1]);
	map_info.color = WHITE;
	fill_dots(&dot, &map_info);
	map_info_init(&map_info);
	window_start(&map_info);
	set_var(&map_info, dot);
	draw_map(&map_info, dot);
	map_info.dot = dot;
	mlx_key_hook(map_info.win_ptr, bay_bay, (void*)(&map_info));
	mlx_loop(map_info.mlx_ptr);
	return (0);
}
