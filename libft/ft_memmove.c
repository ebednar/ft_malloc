/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:28:32 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				count;
	unsigned char		*p_dst;
	const unsigned char	*p_src = src;

	count = 0;
	p_dst = dst;
	if (!len)
		return (dst);
	if (p_dst < p_src)
	{
		while (count < len)
		{
			p_dst[count] = p_src[count];
			count++;
		}
	}
	else
	{
		while (--len)
			p_dst[len] = p_src[len];
		p_dst[len] = p_src[len];
	}
	return (dst);
}
