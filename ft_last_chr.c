/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:57:48 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:57:50 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		last_chr(const char *str, char c)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (str[len - 1] == c)
		return (1);
	else
		return (0);
}