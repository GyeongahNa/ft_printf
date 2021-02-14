/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_for_unsigned_longlong.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:19:40 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 13:21:19 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int		get_oct_mem_size_for_unsigned_longlong(unsigned long long int num)
{
	int size;

	size = 0;
	while (num != 0)
	{
		num = num / 8;
		size++;
	}
	return (size + 1);
}

char	*fill_oct_memory_for_unsigned_longlong(
		int size, unsigned long long int num)
{
	char *result;

	result = malloc(sizeof(char) * size);
	result[size - 1] = '\0';
	size = size - 2;
	while (num != 0)
	{
		result[size] = num % 8 + '0';
		num = num / 8;
		size--;
	}
	return (result);
}

char	*change_to_octal_for_unsigned_longlong(unsigned long long int num)
{
	int		size;
	char	*result;

	if (num == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	size = get_oct_mem_size_for_unsigned_longlong(num);
	result = fill_oct_memory_for_unsigned_longlong(size, num);
	return (result);
}
