/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_formatting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:27:40 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 17:20:38 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

int		**c_flags_infos(char *str)
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

int		**c_format_specifier_infos(char *str, int asterisk_width)
{
	int **infos;
	int **tmp;
	int i;
	int idx;

	infos = set_double(3);
	tmp = c_flags_infos(str);
	i = 0;
	while (i < 1)
	{
		*infos[i] = *tmp[i];
		i++;
	}
	idx = *tmp[i];
	free_double(tmp);
	tmp = width_infos(str, idx, asterisk_width);
	*infos[1] = *tmp[0];
	free_double(tmp);
	if (*infos[1] < 0)
	{
		*infos[0] = 1;
		*infos[1] = (-1) * *infos[1];
	}
	return (infos);
}

int		print_space(int num)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < num)
	{
		write(1, " ", 1);
		n++;
		i++;
	}
	return (n);
}

int		formatting_char(char *str, int asterisk_width, int c)
{
	int **infos;
	int num;

	num = 0;
	infos = c_format_specifier_infos(str, asterisk_width);
	if (*infos[1] <= 1)
	{
		write(1, &c, 1);
		num++;
	}
	else
	{
		if (*infos[0] == 1)
		{
			write(1, &c, 1);
			num += print_space(*infos[1] - 1) + 1;
		}
		else if (*infos[0] == 0)
		{
			num += print_space(*infos[1] - 1) + 1;
			write(1, &c, 1);
		}
	}
	free_double(infos);
	return (num);
}
