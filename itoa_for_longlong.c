/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_longlong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:26:50 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:28:20 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "limits.h"

long long	get_size_for_longlong(long long num)
{
	long long minus_check;
	long long malloc_size;

	minus_check = 0;
	malloc_size = 0;
	if (num < 0)
	{
		minus_check = 1;
		num = (-1) * num;
	}
	else if (num == 0)
		return (2);
	while (num != 0)
	{
		num = num / 10;
		malloc_size++;
	}
	if (minus_check == 1)
		return (malloc_size + 2);
	else
		return (malloc_size + 1);
}

char		*min_for_longlong(void)
{
	char *s;
	char *tmp;

	s = (char *)malloc(sizeof(char) * 21);
	tmp = "-9223372036854775808";
	ft_strcpy(s, tmp);
	return (s);
}

char		*set_str_for_longlong(long long num)
{
	long long	size;
	char		*s;

	size = get_size_for_longlong(num);
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return ((char *)(0));
	if (num < 0)
	{
		num = (-1) * num;
		s[0] = '-';
	}
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

char		*ft_itoa_for_longlong(long long num)
{
	char *s;

	if (num == LLONG_MIN)
	{
		s = min_for_longlong();
		return (s);
	}
	s = set_str_for_longlong(num);
	return (s);
}
