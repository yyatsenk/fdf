/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something_with_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:15:14 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:15:15 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*str_to_int(char **str, t_map_info *map_info)
{
	int		*res;
	int		i;

	i = 0;
	res = (int*)malloc(sizeof(int) * map_info->width);
	while (str[i])
	{
		res[i] = ft_atoi(str[i]);
		i++;
	}
	free_2d(str);
	return (res);
}

static void	to_int(t_map_info *map_info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_info->map_int = (int**)malloc(sizeof(int*) * (map_info->height + 1));
	while (map_info->map_char[i])
	{
		map_info->map_int[i] = str_to_int(ft_strsplit(map_info->map_char[i],\
			' '), map_info);
		i++;
	}
	map_info->map_int[i] = NULL;
	i = 0;
	free_2d(map_info->map_char);
}

void		create_memory(t_map_info *map_info, int fd)
{
	int		i;
	char	*str;

	i = 0;
	map_info->map_char = (char**)malloc(sizeof(char*) * (map_info->height + 1));
	while (get_next_line(fd, &str))
	{
		map_info->map_char[i] = str;
		i++;
	}
	map_info->map_char[i] = NULL;
	i = -1;
	to_int(map_info);
}

int			str_2d_len(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
