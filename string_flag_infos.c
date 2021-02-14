/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_flag_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:34:58 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:34:26 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

int		**str_flags_infos(char *str)
{
	int **flags_infos;
	int i;

	flags_infos = set_double(3);
	i = 0;
	while (str[i] == '-')
	{
		*flags_infos[0] = 1;
		i++;
	}
	*flags_infos[1] = i;
	return (flags_infos);
}

int		str_precision_infos(char *str, int i, int asterisk_precision)
{
	int	precision;
	int	check;
	char	*tmp;
	int	j;

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

int		**str_format_specifier_infos(
		char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(4);
	tmp = str_flags_infos(str);
	i = 0;
	while (i < 1)
	{
		*infos[i] = *tmp[i];
		i++;
	}
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[1] = *tmp[0];
	idx = *tmp[1];
	free_double(tmp);
	*infos[2] = str_precision_infos(str, idx, asterisk_precision);
	return (infos);
}
