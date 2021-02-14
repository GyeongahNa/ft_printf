/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_flag_infos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:34:34 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:47:21 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	**decimal_flags_infos(char *str)
{
	int **flags_infos;
	int i;

	flags_infos = set_double(6);
	i = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '0')
			*flags_infos[0] = 1;
		else if (str[i] == '-')
			*flags_infos[1] = 1;
		else if (str[i] == '+')
			*flags_infos[2] = 1;
		else if (str[i] == ' ')
			*flags_infos[3] = 1;
		i++;
	}
	*flags_infos[4] = i;
	return (flags_infos);
}

int	**decimal_format_specifier_infos(char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(7);
	tmp = decimal_flags_infos(str);
	i = 0;
	while (i < 4)
	{
		*infos[i] = *tmp[i];
		i++;
	}
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[4] = *tmp[0];
	idx = *tmp[1];
	free_double(tmp);
	*infos[5] = precision_infos(str, idx, asterisk_precision);
	if (check_precision(str, idx) == 0)
		*infos[5] = -1;
	else if (*infos[5] >= 0)
		*infos[0] = 0;
	return (infos);
}
