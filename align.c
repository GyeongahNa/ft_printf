/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:23:50 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 20:08:57 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*append_front(char *str, char c, int num)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (ft_strlen(str) + num + 1));
	i = 0;
	while (i < num)
		s[i++] = c;
	s[i] = '\0';
	ft_strcat(s, str);
	return (s);
}

char	*append_leading_zero(char *s, int precision)
{
	char *tmp;

	if (ft_strcmp(s, "0") == 0 && precision == 0)
	{
		tmp = (char *)malloc(sizeof(char));
		tmp[0] = '\0';
		return (tmp);
	}
	if (precision > ft_strlen(s))
		tmp = append_front(s, '0', precision - ft_strlen(s));
	else
		tmp = ft_strdup(s);
	return (tmp);
}

char	*align_to_left(char *s, int width)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (width + 1));
	ft_strcpy(result, s);
	i = ft_strlen(s);
	while (i < width)
		result[i++] = ' ';
	result[i] = '\0';
	return (result);
}
