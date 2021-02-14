/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:00:45 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:03:19 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*new_s;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (!(new_s = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return ((char *)(0));
	ft_strcpy(new_s, s1);
	ft_strcat(new_s, s2);
	return (new_s);
}
