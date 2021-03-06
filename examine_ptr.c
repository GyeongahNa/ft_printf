/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:47:27 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:47:47 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	pass_ptr_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '-')
		i++;
	return (i);
}

int	ptr_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "p") == 0)
		return (1);
	else
		return (-1);
}

int	examine_ptr(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_ptr_flags(str);
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
	return (ptr_final(str, idx));
}
