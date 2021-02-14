/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:48:53 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:49:21 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	pass_unsigned_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	return (i);
}

int	unsigned_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "lu") == 0 || ft_strcmp(str + i, "llu") == 0 ||
			ft_strcmp(str + i, "hhu") == 0 || ft_strcmp(str + i, "hu") == 0 ||
			ft_strcmp(str + i, "u") == 0)
		return (1);
	else
		return (-1);
}

int	examine_unsigned(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_unsigned_flags(str);
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
	return (unsigned_final(str, idx));
}
