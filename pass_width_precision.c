/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:25:02 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 18:09:35 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	**pass_width(const char *str, int i)
{
	int width_check;
	int **tmp;
	int j;

	tmp = (int **)malloc(sizeof(int *) * 3);
	j = 0;
	while (j < 2)
	{
		tmp[j] = (int *)malloc(sizeof(int));
		j++;
	}
	width_check = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		width_check = 1;
		i++;
	}
	*tmp[0] = i;
	*tmp[1] = width_check;
	tmp[2] = 0;
	return (tmp);
}

int	**pass_dot(const char *str, int i)
{
	int dot_check;
	int **tmp;
	int j;

	tmp = (int **)malloc(sizeof(int *) * 3);
	j = 0;
	while (j < 2)
	{
		tmp[j] = (int *)malloc(sizeof(int));
		j++;
	}
	dot_check = 0;
	if (str[i] == '.')
	{
		dot_check = 1;
		i++;
	}
	*tmp[0] = i;
	*tmp[1] = dot_check;
	tmp[2] = 0;
	return (tmp);
}

int	**pass_precision(const char *str, int i, int dot_check)
{
	int precision_check;
	int **tmp;
	int j;

	tmp = (int **)malloc(sizeof(int *) * 3);
	j = 0;
	while (j < 2)
	{
		tmp[j] = (int *)malloc(sizeof(int));
		j++;
	}
	precision_check = 0;
	while (dot_check == 1 && str[i] >= '0' && str[i] <= '9')
	{
		precision_check = 1;
		i++;
	}
	*tmp[0] = i;
	*tmp[1] = precision_check;
	tmp[2] = 0;
	return (tmp);
}
