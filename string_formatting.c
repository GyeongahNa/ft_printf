/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_formatting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:45:19 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 00:03:39 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

char	*cut_str(char *str, int precision)
{
	char *tmp;

	if (precision == -1 || precision >= ft_strlen(str))
		tmp = ft_strdup(str);
	else
		tmp = ft_substr(str, 0, precision);
	return (tmp);
}

char	*set_str_result(char *s, int **infos)
{
	char *result;

	if (*infos[1] <= ft_strlen(s))
		result = ft_strdup(s);
	else
	{
		if (*infos[0] == 1)
			result = align_to_left(s, *infos[1]);
		else
			result = append_front(s, ' ', *infos[1] - ft_strlen(s));
	}
	return (result);
}

char	*str_null(void)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 7);
	ft_strcpy(tmp, "(null)");
	return (tmp);
}

int	**check_width_minus_str(char *format, int asterisk_width, int asterisk_precision)
{
	int		**infos;

	infos = str_format_specifier_infos(
			format, asterisk_width, asterisk_precision);
	if (*infos[1] < 0)
	{
		*infos[0] = 1;
		*infos[1] = (-1) * *infos[1];
	}
	return (infos);
}

char	*formatting_string(char *format, int asterisk_width, int asterisk_precision, char *str)
{
	int		**infos;
	char	*s;
	char	*tmp;

	infos = check_width_minus_str(format, asterisk_width, asterisk_precision);
	if (str == 0)
	{
		s = str_null();
		tmp = cut_str(s, *infos[2]);
		free(s);
		s = tmp;
		tmp = set_str_result(s, infos);
		free(s);
		s = tmp;
		free_double(infos);
		return (s);
	}
	s = cut_str(str, *infos[2]);
	tmp = set_str_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
