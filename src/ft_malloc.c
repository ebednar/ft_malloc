/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:34:23 by rwalder-          #+#    #+#             */
/*   Updated: 2020/01/08 15:34:27 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	int		i;
	void	*ret;

	i = -1;
	pthread_mutex_lock(&g_mutex);
	while (g_preallocated_zones[++i])
	{
		if (size <= g_preallocated_zones[i]->max_size)
		{
			ret = alloc(g_preallocated_zones[i], size);
			pthread_mutex_unlock(&g_mutex);
			return (ret);
		}
	}
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}
