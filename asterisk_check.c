/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:25:25 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 23:56:56 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		width_asterisk_check(char *str, va_list ap)
{
	int	i;
	int width;

	i = 0;
	while (str[i] == '%')
		i++;
	while (str[i] == '0' || str[i] == '-' || str[i] == '+' ||
			str[i] == ' ' || str[i] == '#')
		i++;
	if (str[i] == '*')
	{
		width = va_arg(ap, int);
		return (width);
	}
	return (0);
}

int		precision_asterisk_check(char *str, va_list ap)
{
	int i;
	int precision;

	i = 0;
	while (str[i] == '%')
		i++;
	while (str[i] == '0' || str[i] == '-' || str[i] == '+' ||
			str[i] == ' ' || str[i] == '#')
		i++;
	while (str[i] == '*')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] >= '.')
		i++;
	if (str[i] == '*')
	{
		precision = va_arg(ap, int);
		if (precision < 0)
			return (-1);
		else
			return (precision);
	}
	return (0);
}
