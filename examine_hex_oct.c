/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_hex_oct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:44:53 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:47:05 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int		pass_oct_hex_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == '#')
		i++;
	return (i);
}

int		oct_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "lo") == 0 || ft_strcmp(str + i, "llo") == 0 ||
			ft_strcmp(str + i, "hho") == 0 || ft_strcmp(str + i, "ho") == 0 ||
			ft_strcmp(str + i, "o") == 0)
		return (1);
	else
		return (-1);
}

int		hex_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "lx") == 0 || ft_strcmp(str + i, "llx") == 0 ||
			ft_strcmp(str + i, "hhx") == 0 || ft_strcmp(str + i, "hx") == 0 ||
			ft_strcmp(str + i, "x") == 0)
		return (1);
	else if (ft_strcmp(str + i, "lX") == 0 || ft_strcmp(str + i, "llX") == 0 ||
			ft_strcmp(str + i, "hhX") == 0 || ft_strcmp(str + i, "hX") == 0 ||
			ft_strcmp(str + i, "X") == 0)
		return (1);
	else
		return (-1);
}

int		examine_oct(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_oct_hex_flags(str);
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
	return (oct_final(str, idx));
}

int		examine_hex(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_oct_hex_flags(str);
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
	return (hex_final(str, idx));
}
