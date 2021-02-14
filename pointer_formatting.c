/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_formatting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:26:21 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 17:03:21 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

int		**ptr_flags_infos(char *str)
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

int		**ptr_format_specifier_infos(
		char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(4);
	tmp = ptr_flags_infos(str);
	i = 0;
	*infos[i] = *tmp[i];
	i++;
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[1] = *tmp[0];
	idx = *tmp[1];
	free_double(tmp);
	*infos[2] = precision_infos(str, idx, asterisk_precision);
	if (*infos[1] < 0)
	{
		*infos[0] = 1;
		*infos[1] = (-1) * *infos[1];
	}
	return (infos);
}

char	*set_ptr_result(char *s, int **infos)
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

char	*process_null(int **infos)
{
	char *s;
	char *tmp;

	if (*infos[2] == 0)
		s = ft_strdup("");
	else
	{
		s = ft_strdup("0");
		tmp = append_front(s, '0', *infos[2] - 1);
		free(s);
		s = tmp;
	}
	tmp = append_front(s, 'x', 1);
	free(s);
	s = tmp;
	tmp = append_front(s, '0', 1);
	free(s);
	s = tmp;
	tmp = set_ptr_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}

char	*format_ptr(
		char *str, int asterisk_width, int precision_width, unsigned long ptr)
{
	int		**infos;
	char	*s;
	char	*tmp;

	infos = ptr_format_specifier_infos(str, asterisk_width, precision_width);
	if (ptr == 0)
	{
		s = process_null(infos);
		return (s);
	}
	s = change_to_hexadecimal_for_unsigned_longlong(ptr);
	tmp = append_leading_zero(s, *infos[2]);
	free(s);
	s = tmp;
	tmp = append_front(s, 'x', 1);
	free(s);
	s = tmp;
	tmp = append_front(s, '0', 1);
	free(s);
	s = tmp;
	tmp = set_ptr_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
