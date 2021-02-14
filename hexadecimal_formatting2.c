/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_formatting2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:06:45 by gna               #+#    #+#             */
/*   Updated: 2020/04/22 16:59:15 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	**check_minus_width(char *str, int asterisk_width, int asterisk_precision)
{
	int **infos;

	infos = hex_format_specifier_infos(str, asterisk_width, asterisk_precision);
	if (*infos[3] < 0)
	{
		*infos[1] = 1;
		*infos[3] = (-1) * *infos[3];
	}
	return (infos);
}

char	*formatting_small_hexadecimal(char *str, int asterisk_width, int asterisk_precision, unsigned long long dec)
{
	int	**infos;
	char	*s;
	char	*tmp;
	int	large_hex;

	large_hex = 0;
	infos = check_minus_width(str, asterisk_width, asterisk_precision);
	if (dec == 0)
		*infos[2] = 0;
	s = change_to_hexadecimal_for_unsigned_longlong(dec);
	tmp = check_large_hex(s, large_hex);
	free(s);
	s = tmp;
	tmp = append_leading_zero(s, *infos[4]);
	free(s);
	s = tmp;
	tmp = append_ox(s, infos, dec, large_hex);
	free(s);
	s = tmp;
	tmp = set_hex_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}

char	*formatting_large_hexadecimal(char *str, int asterisk_width, int asterisk_precision, unsigned long long dec)
{
	int	**infos;
	char	*s;
	char	*tmp;
	int	large_hex;

	large_hex = 1;
	infos = check_minus_width(str, asterisk_width, asterisk_precision);
	if (dec == 0)
		*infos[2] = 0;
	s = change_to_hexadecimal_for_unsigned_longlong(dec);
	tmp = check_large_hex(s, large_hex);
	free(s);
	s = tmp;
	tmp = append_leading_zero(s, *infos[4]);
	free(s);
	s = tmp;
	tmp = append_ox(s, infos, dec, large_hex);
	free(s);
	s = tmp;
	tmp = set_hex_result(s, infos);
	free(s);
	s = tmp;
	free_double(infos);
	return (s);
}
