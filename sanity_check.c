/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:32:12 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 21:16:19 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	examine_format_specifier(const char *tmp)
{
	if (last_chr(tmp, '%') == 1)
		return (examine_percent(tmp));
	else if (last_chr(tmp, 'd') == 1)
		return (examine_decimal(tmp));
	else if (last_chr(tmp, 'i') == 1)
		return (examine_decimal(tmp));
	else if (last_chr(tmp, 'u') == 1)
		return (examine_unsigned(tmp));
	else if (last_chr(tmp, 'o') == 1)
		return (examine_oct(tmp));
	else if (last_chr(tmp, 'x') == 1)
		return (examine_hex(tmp));
	else if (last_chr(tmp, 'X') == 1)
		return (examine_hex(tmp));
	else if (last_chr(tmp, 'c') == 1)
		return (examine_char(tmp));
	else if (last_chr(tmp, 'p') == 1)
		return (examine_ptr(tmp));
	else if (last_chr(tmp, 's') == 1)
		return (examine_str(tmp));
	return (-1);
}

int	specifier_check(char c)
{
	if (c != '%' && c != 'd' && c != 'i' && c != 'u' && c != 'o' && c != 'x'
			&& c != 'X' && c != 'c' && c != 'p' && c != 's' && c != '\0')
		return (1);
	else
		return (0);
}

int	str_check(const char *str, char *tmp)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j = 0;
			while (specifier_check(str[i]) == 1)
				tmp[j++] = str[i++];
			tmp[j] = str[i];
			if (str[i] == '\0')
				return (-1);
			tmp[j + 1] = '\0';
			if (examine_format_specifier(tmp) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	sanity_check(const char *str)
{
	char	*tmp;
	int	result;

	if (str == 0)
		return (-1);
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (-1);
	result = str_check(str, tmp);
	free(tmp);
	return (result);
}
