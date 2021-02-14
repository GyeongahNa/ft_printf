/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision_infos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:48:57 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 23:46:44 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		**width_infos(char *str, int i, int asterisk_width)
{
	int		**width_infos;
	char	*tmp;
	int		j;

	width_infos = set_double(3);
	if (str[i] == '*')
	{
		i++;
		*width_infos[0] = asterisk_width;
		*width_infos[1] = i;
		return (width_infos);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	*width_infos[0] = ft_atoi(tmp);
	*width_infos[1] = i;
	free(tmp);
	return (width_infos);
}

int		check_precision(char *str, int i)
{
	int check;

	check = 0;
	if (str[i] == '.')
		check = 1;
	return (check);
}

int		precision_infos(char *str, int i, int asterisk_precision)
{
	int		precision;
	int		check;
	char	*tmp;
	int		j;

	check = 0;
	if (str[i] == '.')
		check = 1;
	if (check == 1)
	{
		i++;
		if (str[i] == '*')
			return (asterisk_precision);
		tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
		j = 0;
		while (str[i] >= '0' && str[i] <= '9')
			tmp[j++] = str[i++];
		tmp[j] = '\0';
		precision = ft_atoi(tmp);
		free(tmp);
	}
	else
		precision = -1;
	return (precision);
}
