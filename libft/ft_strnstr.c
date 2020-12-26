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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t len_h;
	size_t len_n;

	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (len_n == 0)
		return ((char*)haystack);
	if ((len_n > len_h) || (len_n > len) || len_h == 0)
		return (NULL);
	i = 0;
	while (i < (len_h - len_n + 1) && i < (len - len_n + 1))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (j < len_n))
		{
			j++;
			if (j == len_n)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
