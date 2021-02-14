/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_formatting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:30:32 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 16:57:16 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*str_without_sign(long long dec)
{
	char *str;
	char *itoa;

	if (dec < 0)
	{
		itoa = ft_itoa_for_longlong(dec);
		str = ft_substr(itoa, 1, ft_strlen(itoa) - 1);
		free(itoa);
	}
	else
		str = ft_itoa_for_longlong(dec);
	return (str);
}

char	*append_sign(char *s, long long dec, int **infos)
{
	char *tmp;

	if (dec < 0)
		tmp = append_front(s, '-', 1);
	else if (dec >= 0 && *infos[2] == 1)
		tmp = append_front(s, '+', 1);
	else if (dec >= 0 && *infos[3] == 1)
		tmp = append_front(s, ' ', 1);
	else
		tmp = ft_strdup(s);
	return (tmp);
}

char	*align_to_right_append_sign(char *s, int width, long long dec)
{
	char	*result;
	char	*itoa;
	int		i;

	result = malloc(sizeof(char) * (width + 1));
	result[0] = s[0];
	i = 1;
	while (i < width - (ft_strlen(s) - 1))
		result[i++] = '0';
	result[i] = '\0';
	itoa = str_without_sign(dec);
	ft_strcat(result, itoa);
	free(itoa);
	return (result);
}

char	*set_decimal_result(char *s, int **infos, long long dec)
{
	char *result;

	result = 0;
	if (ft_strlen(s) >= *infos[4])
		result = ft_strdup(s);
	else
	{
		if (*infos[1] == 1)
			result = align_to_left(s, *infos[4]);
		else if (*infos[0] == 1)
		{
			if (*infos[2] == 1 || *infos[3] == 1 || dec < 0)
				result = align_to_right_append_sign(s, *infos[4], dec);
			else if (*infos[2] == 0 && *infos[3] == 0 && dec >= 0)
				result = append_front(s, '0', *infos[4] - ft_strlen(s));
		}
		else
			result = append_front(s, ' ', *infos[4] - ft_strlen(s));
	}
	return (result);
}

char	*formatting_decimal(char *str, int asterisk_width,
		int asterisk_precision, long long dec)
{
	int	**infos;
	char	*s;
	char	*tmp;

	infos = decimal_format_specifier_infos(str, asterisk_width,
			asterisk_precision);
	if (*infos[4] < 0)
	{
		*infos[1] = 1;
		*infos[4] = (-1) * *infos[4];
	}
	if (*infos[5] < 0)
		*infos[5] = -1;
	s = str_without_sign(dec);
	tmp = append_leading_zero(s, *infos[5]);
	free(s);
	s = tmp;
	tmp = append_sign(s, dec, infos);
	free(s);
	s = tmp;
	tmp = set_decimal_result(s, infos, dec);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
