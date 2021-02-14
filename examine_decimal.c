/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:44:17 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 18:08:27 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	pass_decimal_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == ' ' || str[i] == '+')
		i++;
	return (i);
}

int	decimal_final(const char *str, int i)
{
	if (ft_strcmp(str + i, "ld") == 0 || ft_strcmp(str + i, "lld") == 0 ||
			ft_strcmp(str + i, "hhd") == 0 || ft_strcmp(str + i, "hd") == 0 ||
			ft_strcmp(str + i, "d") == 0)
		return (1);
	else if (ft_strcmp(str + i, "li") == 0 || ft_strcmp(str + i, "lli") == 0 ||
			ft_strcmp(str + i, "hhi") == 0 || ft_strcmp(str + i, "hi") == 0 ||
			ft_strcmp(str + i, "i") == 0)
		return (1);
	else
		return (-1);
}

int	examine_decimal(const char *str)
{
	int idx;
	int width_check;
	int dot_check;
	int precision_check;
	int **tmp;

	idx = pass_decimal_flags(str);
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
	return (decimal_final(str, idx));
}
