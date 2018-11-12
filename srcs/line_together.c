/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_together.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:04:25 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:04:26 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_2d(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

static void	help_me(t_cc *c)
{
	int		tmp;

	if (c->x0 < 0 || c->y0 < 0)
	{
		tmp = c->x1;
		c->x1 = c->x0;
		c->x0 = tmp;
		tmp = c->y1;
		c->y1 = c->y0;
		c->y0 = tmp;
	}
	c->deltax = abs(c->x1 - c->x0);
	c->deltay = abs(c->y1 - c->y0);
}

void		make_line(t_map_info *map_info, t_cc c, int error2, t_dot *dot)
{
	int		signx;
	int		signy;
	int		error;
	int		color_copy;

	help_me(&c);
	color_copy = dot->color;
	signx = c.x0 < c.x1 ? 1 : -1;
	signy = c.y0 < c.y1 ? 1 : -1;
	error = c.deltax - c.deltay;
	mlx_pixel_put(map_info->mlx_ptr, map_info->win_ptr, c.x1, c.y1, dot->color);
	while ((c.x0 != c.x1 || c.y0 != c.y1) && c.x0 >= 0 && c.y0 >= 0)
	{
		if (dot->altitude && dot->color != WHITE)
			dot->color += 2;
		mlx_pixel_put(map_info->mlx_ptr, map_info->win_ptr,\
			c.x0, c.y0, dot->color);
		error2 = error * 2;
		if (error2 > -c.deltay && (c.x0 += signx))
			error -= c.deltay;
		if (error2 < c.deltax && (c.y0 += signy))
			error += c.deltax;
	}
	dot->color = color_copy;
}
