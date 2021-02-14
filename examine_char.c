/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:37:35 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 13:45:49 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	pass_char_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '-')
		i++;
	return (i);
}

int	char_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "c") == 0)
		return (1);
	else
		return (-1);
}

int	examine_char(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_char_flags(str);
	tmp = pass_width(str, idx);
	idx = *tmp[0];
	width_check = *tmp[1];
	free_double(tmp);
	if (width_check == 0 && str[idx] == '*')
		idx++;
	tmp = pass_dot(str, idx);
	idx = *tmp[0];
	dot_check = *tmp[1];
	free_double(tmp);
	tmp = pass_precision(str, idx, dot_check);
	idx = *tmp[0];
	precision_check = *tmp[1];
	free_double(tmp);
	if (dot_check == 1 && precision_check == 0 && str[idx] == '*')
		idx++;
	return (char_final(str, idx));
}
