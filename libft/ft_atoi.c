/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:28:08 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	ret;
	int		count;
	int		sign;

	ret = 0;
	count = 0;
	sign = 1;
	while ((str[count] == ' ' || str[count] == '\t' || str[count] == '\n'
			|| str[count] == '\r' || str[count] == '\v' || str[count] == '\f')
			&& str[count] != '\0')
		count++;
	if (str[count] == '+')
		count++;
	else if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		ret *= 10;
		ret = ret + (str[count++] - '0');
	}
	return (ret * sign);
}
