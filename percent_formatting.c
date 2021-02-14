/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_formatting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:30:32 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:04:25 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*set_percent_result(char *s, int **infos)
{
	char *result;

	result = 0;
	if (ft_strlen(s) >= *infos[2])
		result = ft_strdup(s);
	else
	{
		if (*infos[1] == 1)
			result = align_to_left(s, *infos[2]);
		else if (*infos[0] == 1)
			result = append_front(s, '0', *infos[2] - ft_strlen(s));
		else
			result = append_front(s, ' ', *infos[2] - ft_strlen(s));
	}
	return (result);
}

char	*formatting_percent(char *str, int asterisk_width)
{
	int		**infos;
	char	*s;
	char	*tmp;

	infos = percent_format_specifier_infos(str, asterisk_width);
	if (*infos[2] < 0)
	{
		*infos[1] = 1;
		*infos[2] = (-1) * *infos[2];
	}
	s = ft_strdup("%");
	tmp = set_percent_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
