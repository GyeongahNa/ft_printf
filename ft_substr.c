/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:02:07 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:02:09 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	end;
	char	*sub_s;

	i = 0;
	if (!(sub_s = malloc(sizeof(char) * (len + 1))))
		return ((char *)(0));
	if (start < (size_t)ft_strlen(s))
	{
		end = start + len;
		while (start < end && s[start] != '\0')
		{
			sub_s[i] = s[start];
			i++;
			start++;
		}
		sub_s[i] = '\0';
		return (sub_s);
	}
	return ((char *)(0));
}
