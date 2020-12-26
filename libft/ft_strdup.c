/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:59:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*ret;

	count = 0;
	while (s1[count] != '\0')
		count++;
	ret = (char *)malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		ret[count] = s1[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
