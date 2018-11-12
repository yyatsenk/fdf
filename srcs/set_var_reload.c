/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_reload.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:26:54 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:26:58 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_var(t_map_info *map_info, t_dot *dot)
{
	t_dot		*begin_copy;

	begin_copy = dot;
	while (dot)
	{
		dot->x_max = dot->x + (dot->x * map_info->zoom);
		dot->y_max = dot->y + (dot->y * map_info->zoom);
		dot->z_max = dot->altitude * map_info->depth;
		dot->x_min = (map_info->d_width * dot->x_max)\
		- (map_info->d_height * dot->y_max);
		dot->y_min = (dot->z_max
			+ ((map_info->d_width / 2) * dot->x_max)
			+ ((map_info->d_height / 2) * dot->y_max));
		dot->x_min = dot->x_min * cos(map_info->x_rot)\
		- dot->y_min * sin(map_info->x_rot);
		dot->y_min = dot->x_min * sin(map_info->x_rot)\
		+ dot->y_min * cos(map_info->x_rot);
		dot->x_min += map_info->x_move * 1.78;
		dot->y_min += map_info->y_move / 3;
		dot = dot->next;
	}
	dot = begin_copy;
}

static void		set(t_map_info *m_i, char *to_do)
{
	if (to_do[0] == 'x' && to_do[1] == '+')
		m_i->x_move += 20;
	if (to_do[0] == 'x' && to_do[1] == '-')
		m_i->x_move -= 20;
	if (to_do[0] == 'y' && to_do[1] == '+')
		m_i->y_move += 20;
	if (to_do[0] == 'y' && to_do[1] == '-')
		m_i->y_move -= 20;
	if (to_do[0] == '+')
		m_i->zoom += 1;
	if (to_do[0] == '-')
		m_i->zoom -= 1;
	if (to_do[0] == 'z' && to_do[1] == '+')
		m_i->depth += 1;
	if (to_do[0] == 'z' && to_do[1] == '-')
		m_i->depth -= 1;
	if (to_do[0] == 'r' && to_do[1] == '+')
		m_i->x_rot += 0.3;
	if (to_do[0] == 'r' && to_do[1] == '-')
		m_i->x_rot -= 0.3;
}

static void		reload(char *to_do, t_map_info *m_i)
{
	t_dot		*dot_copy;

	dot_copy = m_i->dot;
	set(m_i, to_do);
	set_var(m_i, m_i->dot);
	m_i->dot = dot_copy;
	while (m_i->dot)
	{
		if (m_i->depth * m_i->dot->altitude > 0 && m_i->dot->altitude)
			m_i->dot->color = RED;
		if (m_i->depth * m_i->dot->altitude < 0 && m_i->dot->altitude)
			m_i->dot->color = GREEN;
		if (m_i->depth * m_i->dot->altitude == 0)
			m_i->dot->color = WHITE;
		m_i->dot = m_i->dot->next;
	}
	m_i->dot = dot_copy;
	mlx_clear_window(m_i->mlx_ptr, m_i->win_ptr);
	draw_map(m_i, dot_copy);
	free(to_do);
}

static void		make_command(int keycode, t_map_info *m_i)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 124)
		reload(ft_strdup("x+"), m_i);
	else if (keycode == 123)
		reload(ft_strdup("x-"), m_i);
	else if (keycode == 125)
		reload(ft_strdup("y+"), m_i);
	else if (keycode == 126)
		reload(ft_strdup("y-"), m_i);
	else if (keycode == 13)
		reload(ft_strdup("+"), m_i);
	else if (keycode == 1)
		reload(ft_strdup("-"), m_i);
	else if (keycode == 78)
		reload(ft_strdup("z+"), m_i);
	else if (keycode == 69)
		reload(ft_strdup("z-"), m_i);
	else if (keycode == 47)
		reload(ft_strdup("r+"), m_i);
	else if (keycode == 43)
		reload(ft_strdup("r-"), m_i);
}

int				bay_bay(int keycode, void *map_info)
{
	t_map_info	*m_i;

	m_i = (t_map_info*)map_info;
	make_command(keycode, m_i);
	return (0);
}
