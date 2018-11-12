/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read_and_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:18:07 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:18:08 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	help(t_map_info *map_info, int *fd, char *file)
{
	char	*str;
	char	**str_sp;

	str = NULL;
	while (get_next_line(*fd, &str))
	{
		str_sp = ft_strsplit(str, ' ');
		if (str_2d_len(str_sp) != map_info->width)
		{
			free(str);
			free_2d(str_sp);
			write(1, "Found wrong line length. Exiting.\n",\
				ft_strlen("Found wrong line length. Exiting.\n"));
			exit(1);
		}
		free_2d(str_sp);
		free(str);
		map_info->height++;
	}
	close(*fd);
	*fd = open(file, O_RDONLY);
}

void		file_read_and_fill(t_map_info *map_info, char *file)
{
	int		fd;
	char	*str;
	char	**str_sp;
	char	**str_sp_copy;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit(1);
	map_info->height = 1;
	get_next_line(fd, &str);
	if (!str)
		exit(1);
	str_sp = ft_strsplit(str, ' ');
	str_sp_copy = str_sp;
	while (str_sp[0])
	{
		map_info->width++;
		str_sp++;
	}
	free_2d(str_sp_copy);
	free(str);
	help(map_info, &fd, file);
	create_memory(map_info, fd);
	close(fd);
}
