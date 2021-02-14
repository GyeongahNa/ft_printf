/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:54:06 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 17:39:50 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_conversion(char *str, int width, int precision, va_list ap)
{
	char *tmp;

	tmp = 0;
	if (ft_find_str(str, "hhu") == 1)
		tmp = formatting_unsigned(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "hu") == 1)
		tmp = formatting_unsigned(
			str + 1, width, precision, va_arg(ap, unsigned int));
	else if (ft_find_str(str, "llu") == 1)
		tmp = formatting_unsigned(
			str + 1, width, precision, va_arg(ap, unsigned long long));
	else if (ft_find_str(str, "lu") == 1)
		tmp = formatting_unsigned(
			str + 1, width, precision, va_arg(ap, unsigned long));
	else if (ft_find_chr(str, 'u') == 1)
		tmp = formatting_unsigned(
			str + 1, width, precision, va_arg(ap, unsigned int));
	return (tmp);
}
