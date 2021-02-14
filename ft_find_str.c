/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:58:20 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:58:24 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_str(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] != '\0')
			{
				if (s1[i + j] != s2[j])
					break ;
				j++;
			}
			if (j == ft_strlen(s2))
				return (1);
		}
		i++;
	}
	return (0);
}
