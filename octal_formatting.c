/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:21:35 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 11:31:29 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*append_o(char *s, int **infos, unsigned long long dec)
{
	char *tmp;

	if (dec == 0)
		tmp = ft_strdup(s);
	if (*infos[2] == 1)
	{
		if (s[0] == '0')
			tmp = ft_strdup(s);
		else
			tmp = append_front(s, '0', 1);
	}
	else
		tmp = ft_strdup(s);
	return (tmp);
}

char	*set_oct_result(char *s, int **infos)
{
	char *result;

	result = 0;
	if (*infos[3] <= ft_strlen(s))
		result = ft_strdup(s);
	else
	{
		if (*infos[1] == 1)
			result = align_to_left(s, *infos[3]);
		else if (*infos[0] == 1)
			result = append_front(s, '0', *infos[3] - ft_strlen(s));
		else if (*infos[0] == 0 && *infos[1] == 0)
			result = append_front(s, ' ', *infos[3] - ft_strlen(s));
	}
	return (result);
}

char	*formatting_octal(char *str,
		int asterisk_width, int asterisk_precision, unsigned long long dec)
{
	int		**infos;
	char	*s;
	char	*tmp;

	infos = octal_format_specifier_infos(
			str, asterisk_width, asterisk_precision);
	if (dec == 0)
		*infos[2] = 0;
	if (*infos[3] < 0)
	{
		*infos[1] = 1;
		*infos[3] = (-1) * *infos[3];
	}
	s = change_to_octal_for_unsigned_longlong(dec);
	tmp = append_leading_zero(s, *infos[4]);
	free(s);
	s = tmp;
	tmp = append_o(s, infos, dec);
	free(s);
	s = tmp;
	tmp = set_oct_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
