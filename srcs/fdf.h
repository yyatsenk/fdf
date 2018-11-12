/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:10:24 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/22 11:10:25 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include <math.h>

# define COLOR_GRID 0x00555555
# define RED 0x00C00000
# define PINK 0x00FF8585
# define GREEN 0x0000C000
# define LIGHT_GR 0x0085FF85
# define BLACK 0x000000
# define END 0x0095B6
# define TEPLO 0xFFBCEB1
# define WHITE 0xFFFFFF
# define HEIGHT	1920
# define WIDTH	1080

typedef struct	s_b
{
	double		altitude;
	double		x;
	double		y;
	double		x_min;
	double		y_min;
	double		x_max;
	double		y_max;
	double		z_max;
	int			color;
	struct s_b	*next;
	struct s_b	*prev;
}				t_dot;

typedef struct	s_a
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map_char;
	double		zoom;
	int			depth;
	double		d_width;
	double		d_height;
	double		x_move;
	double		y_move;
	double		x_rot;
	int			width;
	int			height;
	int			**map_int;
	t_dot		*dot;
	int			color;
}				t_map_info;

typedef struct	s_coo
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	double		deltax;
	double		deltay;
}				t_cc;
void			make_line(t_map_info *map_info, t_cc c, int error2, t_dot *dot);
void			free_2d(char **str);
void			create_memory(t_map_info *map_info, int fd);
int				str_2d_len(char **str);
void			file_read_and_fill(t_map_info *map_info, char *file);
void			window_start(t_map_info *map_info);
void			draw_map(t_map_info *map_info, t_dot *dot);
void			set_var(t_map_info *map_info, t_dot *dot);
int				bay_bay(int keycode, void *map_info);
#endif
