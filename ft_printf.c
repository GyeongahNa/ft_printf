/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:10:05 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 17:28:29 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

char	*get_format_specifier(char *str)
{
	char	*tmp;
	int	i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i] != 's' && str[i] != 'c' && str[i] != 'd' && str[i] != 'i'
			&& str[i] != 'u' && str[i] != 'o' && str[i] != 'x' && str[i] != 'X'
			&& str[i] != 'p' && (!(str[i] == '%' && i != 0)))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = str[i];
	tmp[i + 1] = '\0';
	return (tmp);
}

int	print_conversioned(char *str, int width, int precision, va_list ap)
{
	char	*tmp;

	tmp = 0;
	if (ft_find_chr(str, 'c') == 1)
		return (formatting_char(str + 1, width, va_arg(ap, int)));
	else if (ft_find_chr(str, 'd') == 1)
		tmp = decimal_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'i') == 1)
		tmp = integer_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'x') == 1)
		tmp = hexadecimal_small_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'X') == 1)
		tmp = hexadecimal_large_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'o') == 1)
		tmp = octal_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'u') == 1)
		tmp = unsigned_conversion(str, width, precision, ap);
	else if (ft_find_chr(str, 'p') == 1)
		tmp = format_ptr(str + 1, width, precision, va_arg(ap, unsigned long));
	else if (ft_find_chr(str, 's') == 1)
		tmp = formatting_string(str + 1, width, precision, va_arg(ap, char*));
	else if (last_chr(str, '%') == 1)
		tmp = formatting_percent(str + 1, width);
	return (ft_putstr(tmp));
}

int	*print_character(char *str, int i, int num, va_list ap)
{
	char	*tmp;
	int	*result;

	result = (int *)malloc(sizeof(int) * 2);
	if (str[i] != '%')
	{
		ft_putchar(str[i]);
		num++;
	}
	else
	{
		tmp = get_format_specifier(str + i);
		num += print_conversioned(tmp, width_asterisk_check(tmp, ap),
				precision_asterisk_check(tmp, ap), ap);
		i += ft_strlen(tmp) - 1;
		free(tmp);
	}
	result[0] = num;
	result[1] = i;
	return (result);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;
	int		*arr;

	if (sanity_check(str) == -1)
		return (-1);
	va_start(ap, str);
	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		arr = print_character(str, i, num, ap);
		num = arr[0];
		i = arr[1];
		free(arr);
		arr = NULL;
		i++;
	}
	va_end(ap);
	return (num);
}
