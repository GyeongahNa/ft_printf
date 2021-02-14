/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_flag_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:17:02 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:51:36 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	**octal_flags_infos(char *str)
{
	int **flags_infos;
	int i;

	flags_infos = set_double(5);
	i = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == '#')
	{
		if (str[i] == '0')
			*flags_infos[0] = 1;
		else if (str[i] == '-')
			*flags_infos[1] = 1;
		else if (str[i] == '#')
			*flags_infos[2] = 1;
		i++;
	}
	*flags_infos[3] = i;
	return (flags_infos);
}

int	**octal_format_specifier_infos(char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(6);
	tmp = octal_flags_infos(str);
	i = 0;
	while (i < 3)
	{
		*infos[i] = *tmp[i];
		i++;
	}
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[3] = *tmp[0];
	idx = *tmp[1];
	free_double(tmp);
	*infos[4] = precision_infos(str, idx, asterisk_precision);
	if (check_precision(str, idx) == 0)
		*infos[4] = -1;
	else if (*infos[4] >= 0)
		*infos[0] = 0;
	return (infos);
}
