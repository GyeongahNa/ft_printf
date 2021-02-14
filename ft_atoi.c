/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 11:50:13 by gna               #+#    #+#             */
/*   Updated: 2020/04/21 11:50:29 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int decimal;
	int minus_check;

	i = 0;
	decimal = 0;
	minus_check = 0;
	if (str[0] == '-')
	{
		minus_check = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = (decimal + str[i] - '0') * 10;
		i++;
	}
	decimal = decimal / 10;
	if (minus_check == 1)
		decimal = decimal * (-1);
	return (decimal);
}
