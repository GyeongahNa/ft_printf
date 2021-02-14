/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_formatting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:47:51 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:30:57 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*set_unsigned_result(char *s, int **infos)
{
	char *result;

	result = 0;
	if (*infos[2] <= ft_strlen(s))
		result = ft_strdup(s);
	else
	{
		if (*infos[1] == 1)
			result = align_to_left(s, *infos[2]);
		else if (*infos[0] == 1)
			result = append_front(s, '0', *infos[2] - ft_strlen(s));
		else if (*infos[0] == 0 && *infos[1] == 0)
			result = append_front(s, ' ', *infos[2] - ft_strlen(s));
	}
	return (result);
}

char	*formatting_unsigned(char *str, int asterisk_width,
		int asterisk_precision, unsigned long long dec)
{
	int		**infos;
	char	*s;
	char	*tmp;

	infos = unsigned_format_specifier_infos(
			str, asterisk_width, asterisk_precision);
	if (*infos[2] < 0)
	{
		*infos[1] = 1;
		*infos[2] = (-1) * *infos[2];
	}
	s = ft_itoa_for_unsigned_longlong(dec);
	tmp = append_leading_zero(s, *infos[3]);
	free(s);
	s = tmp;
	tmp = set_unsigned_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
