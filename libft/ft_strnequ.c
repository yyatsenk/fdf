/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:01:08 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 13:01:09 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1 && s2 && s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if ((s1 && s2 && s1[i] == '\0' && s2[i] == '\0') || i == n)
		return (1);
	else
		return (0);
}
