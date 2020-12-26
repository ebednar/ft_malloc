/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:30:00 by rwalder-          #+#    #+#             */
/*   Updated: 2020/05/24 19:30:00 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_putnbr_ul(unsigned long n)
{
	int		count;
	char	ret[40];
	long	num;

	count = 0;
	num = n;
	while (count < 40)
		ret[count++] = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (num > 0)
	{
		ret[--count] = '0' + (num % 10);
		num = num / 10;
	}
	while (count < 40)
		ft_putchar(ret[count++]);
}

void	symtohex(unsigned long long c, char *hex, unsigned int size)
{
	int value;
	int count;

	count = size - 1;
	while (count >= 0)
		hex[count--] = '0';
	count = size - 1;
	while (c > 0)
	{
		value = c;
		c = c / 16;
		value = value - c * 16;
		if (value >= 10)
			hex[count--] = 'a' + value - 10;
		else
			hex[count--] = '0' + value;
	}
}

void	print_address(void *p)
{
	unsigned long	value;
	char			str[50];
	int				i;
	int				skip;

	value = (unsigned long)p;
	i = -1;
	while (++i < 50)
		str[i] = 0;
	symtohex(value, (void*)&str, 49);
	ft_putstr("0x");
	skip = 1;
	i = -1;
	while (++i < 50)
	{
		if (str[i] != '0' && skip)
			skip = 0;
		if (!skip)
			ft_putchar(str[i]);
	}
}
