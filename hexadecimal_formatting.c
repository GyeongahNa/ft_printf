/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_formatting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:16:17 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 16:58:52 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*append_ox(char *s, int **infos, unsigned long long dec, int large_hex)
{
	char *tmp1;
	char *tmp2;

	if (dec == 0)
		tmp2 = ft_strdup(s);
	else if (*infos[2] == 1)
	{
		if (large_hex == 0)
			tmp1 = append_front(s, 'x', 1);
		else
			tmp1 = append_front(s, 'X', 1);
		tmp2 = append_front(tmp1, '0', 1);
		free(tmp1);
	}
	else
		tmp2 = ft_strdup(s);
	return (tmp2);
}

char	*align_to_right_append_ox(char *s, int width)
{
	char	*result;
	int	i;
	int	j;

	result = malloc(sizeof(char) * (width + 1));
	result[width] = '\0';
	result[0] = s[0];
	result[1] = s[1];
	i = 2;
	while (i < width - (ft_strlen(s) - 2))
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	j = 2;
	while (i < width)
	{
		result[i] = s[j];
		i++;
		j++;
	}
	return (result);
}

char	*set_hex_result(char *s, int **infos)
{
	char *result;

	result = 0;
	if (*infos[3] <= ft_strlen(s))
		result = ft_strdup(s);
	else
	{
		if (*infos[1] == 1)
			result = align_to_left(s, *infos[3]);
		else if (*infos[0] == 1)
		{
			if (*infos[2] == 1)
				result = align_to_right_append_ox(s, *infos[3]);
			else
				result = append_front(s, '0', *infos[3] - ft_strlen(s));
		}
		else if (*infos[0] == 0 && *infos[1] == 0)
			result = append_front(s, ' ', *infos[3] - ft_strlen(s));
	}
	return (result);
}

char	*check_large_hex(char *str, int large_hex)
{
	char	*tmp;
	int	i;

	tmp = ft_strdup(str);
	if (large_hex == 1)
	{
		i = 0;
		while (tmp[i] != '\0')
		{
			tmp[i] = ft_toupper(tmp[i]);
			i++;
		}
	}
	return (tmp);
}
