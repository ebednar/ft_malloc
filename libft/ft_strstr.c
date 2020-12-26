/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:47:37 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t len_h;
	size_t len_n;

	len_h = ft_strlen((char*)haystack);
	len_n = ft_strlen((char*)needle);
	if (len_n == 0)
		return ((char*)haystack);
	if (len_n > len_h)
		return (NULL);
	i = 0;
	while (i < (len_h - len_n + 1))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			j++;
			if (j == len_n)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
