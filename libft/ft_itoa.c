/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:41:53 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	ret;
	long	num;

	ret = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		ret++;
	}
	while (num > 0)
	{
		ret++;
		num = num / 10;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	long	len;
	char	*ret;
	long	num;

	len = ft_intlen(n);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	num = n;
	ret[len--] = '\0';
	if (num < 0)
	{
		ret[0] = '-';
		num *= -1;
		len--;
	}
	while (len >= 0)
	{
		ret[(n < 0) ? (len + 1) : len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (ret);
}
