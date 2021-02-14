/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_flag_infos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:46:24 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:49:20 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		**unsigned_flags_infos(char *str)
{
	int **flags_infos;
	int i;

	flags_infos = set_double(4);
	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0')
			*flags_infos[0] = 1;
		else if (str[i] == '-')
			*flags_infos[1] = 1;
		i++;
	}
	*flags_infos[2] = i;
	return (flags_infos);
}

int		**unsigned_format_specifier_infos(
		char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(5);
	tmp = unsigned_flags_infos(str);
	i = 0;
	while (i < 2)
	{
		*infos[i] = *tmp[i];
		i++;
	}
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[2] = *tmp[0];
	idx = *tmp[1];
	free_double(tmp);
	*infos[3] = precision_infos(str, idx, asterisk_precision);
	if (check_precision(str, idx) == 0)
		*infos[3] = -1;
	else if (*infos[3] >= 0)
		*infos[0] = 0;
	return (infos);
}
