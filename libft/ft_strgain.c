/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:25:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgain(char *old_str, size_t old_size, size_t new_size)
{
	char *new_str;

	if ((old_size >= new_size) || old_str == NULL)
		return (NULL);
	new_str = ft_strnew(new_size);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, old_str, old_size);
	while (old_size <= new_size)
		new_str[++old_size] = '\0';
	ft_strdel(&old_str);
	return (new_str);
}
