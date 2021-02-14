/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:31:48 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 17:39:21 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

char	*decimal_conversion(char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hhd") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	else if (ft_find_str(str, "hd") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	else if (ft_find_str(str, "lld") == 1)
		tmp = formatting_decimal(
				str + 1, width, precision, va_arg(ap, long long));
	else if (ft_find_str(str, "ld") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, long));
	else if (ft_find_chr(str, 'd') == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	return (tmp);
}

char	*integer_conversion(char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hhi") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	else if (ft_find_str(str, "hi") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	else if (ft_find_str(str, "lli") == 1)
		tmp = formatting_decimal(
			str + 1, width, precision, va_arg(ap, long long));
	else if (ft_find_str(str, "li") == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, long));
	else if (ft_find_chr(str, 'i') == 1)
		tmp = formatting_decimal(str + 1, width, precision, va_arg(ap, int));
	return (tmp);
}

char	*hexadecimal_large_conversion(
		char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hhX") == 1)
		tmp = formatting_large_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "hX") == 1)
		tmp = formatting_large_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "llX") == 1)
		tmp = formatting_large_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned long long));
	else if (ft_find_str(str, "lX") == 1)
		tmp = formatting_large_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned long));
	else if (ft_find_chr(str, 'X') == 1)
		tmp = formatting_large_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	return (tmp);
}

char	*hexadecimal_small_conversion(
		char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hhx") == 1)
		tmp = formatting_small_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "hx") == 1)
		tmp = formatting_small_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "llx") == 1)
		tmp = formatting_small_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned long long));
	else if (ft_find_str(str, "lx") == 1)
		tmp = formatting_small_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned long));
	else if (ft_find_chr(str, 'x') == 1)
		tmp = formatting_small_hexadecimal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	return (tmp);
}

char	*octal_conversion(char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hho") == 1)
		tmp = formatting_octal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "ho") == 1)
		tmp = formatting_octal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "llo") == 1)
		tmp = formatting_octal(
			str + 1, width, precision, va_arg(ap, unsigned long long));
	else if (ft_find_str(str, "lo") == 1)
		tmp = formatting_octal(
			str + 1, width, precision, va_arg(ap, unsigned long));
	else if (ft_find_chr(str, 'o') == 1)
		tmp = formatting_octal(
			str + 1, width, precision, va_arg(ap, unsigned int));
	return (tmp);
}
