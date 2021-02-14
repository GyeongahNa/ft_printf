/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_unsigned_longlong.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:28:46 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:29:12 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "limits.h"

int	get_size_for_unsigned_longlong(unsigned long long num)
{
	int malloc_size;

	malloc_size = 0;
	if (num == 0)
		return (2);
	while (num != 0)
	{
		num = num / 10;
		malloc_size++;
	}
	return (malloc_size + 1);
}

char	*ft_itoa_for_unsigned_longlong(unsigned long long int num)
{
	char	*s;
	int	size;

	size = get_size_for_unsigned_longlong(num);
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return ((char *)(0));
	s[size - 1] = '\0';
	size = size - 2;
	if (num == 0)
		s[size] = '0';
	while (num != 0)
	{
		s[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	return (s);
}
