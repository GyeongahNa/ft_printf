/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_for_unsigned_longlong.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:12:33 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:14:53 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int		get_hex_mem_size_for_unsigned_longlong(unsigned long long int num)
{
	int size;

	size = 0;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	return (size + 1);
}

char	*fill_hex_memory_for_unsigned_longlong(int size,
		unsigned long long int num)
{
	char *result;

	result = malloc(sizeof(char) * size);
	result[size - 1] = '\0';
	size = size - 2;
	while (num != 0)
	{
		if (num % 16 == 10)
			result[size] = 'a';
		else if (num % 16 == 11)
			result[size] = 'b';
		else if (num % 16 == 12)
			result[size] = 'c';
		else if (num % 16 == 13)
			result[size] = 'd';
		else if (num % 16 == 14)
			result[size] = 'e';
		else if (num % 16 == 15)
			result[size] = 'f';
		else
			result[size] = num % 16 + '0';
		num = num / 16;
		size--;
	}
	return (result);
}

char	*change_to_hexadecimal_for_unsigned_longlong(unsigned
		long long num)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	if (num == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[i] = '0';
		result[i + 1] = '\0';
		return (result);
	}
	size = get_hex_mem_size_for_unsigned_longlong(num);
	result = fill_hex_memory_for_unsigned_longlong(size, num);
	return (result);
}
