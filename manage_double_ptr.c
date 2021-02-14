/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_double_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 12:31:14 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 12:31:28 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		**set_double(int size)
{
	int **double_ptr;
	int i;

	double_ptr = (int**)malloc(sizeof(int*) * size);
	i = 0;
	while (i < size - 1)
	{
		double_ptr[i] = (int *)malloc(sizeof(int));
		*double_ptr[i++] = 0;
	}
	double_ptr[i] = 0;
	return (double_ptr);
}

void	free_double(int **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != 0)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
