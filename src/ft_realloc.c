/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:30:00 by rwalder-          #+#    #+#             */
/*   Updated: 2020/05/24 19:30:00 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t	search_alloc(t_zone *zone, void *ptr, t_preallocated_zone *pre)
{
	int	j;

	j = -1;
	if (pre->max_size == (size_t)(-1))
		return ((zone->zone == ptr) ? (zone->size) : (0));
	while (++j < (int)zone->alloc_count)
	{
		if (ptr == zone->meta[j].address)
			return (zone->meta[j].size);
	}
	return (0);
}

size_t			size_alloc(void *ptr)
{
	int		i;
	t_zone	*zone;

	i = -1;
	while (g_preallocated_zones[++i])
	{
		if (!g_preallocated_zones[i]->p_zone)
			continue;
		zone = g_preallocated_zones[i]->p_zone;
		while (zone)
		{
			if (ptr < zone->zone || ptr > (zone->zone + zone->alloc_size))
			{
				zone = zone->next;
				continue;
			}
			if (g_preallocated_zones[i]->max_size == (size_t)(-1)
					&& ptr != zone->zone)
				continue;
			else
				return (search_alloc(zone, ptr, g_preallocated_zones[i]));
		}
	}
	return (0);
}

void			*realloc(void *ptr, size_t size)
{
	size_t	old_size;
	void	*new_ptr;

	if (!ptr || !size)
		return (NULL);
	if (!(old_size = size_alloc(ptr)))
		return (NULL);
	if (!(new_ptr = malloc(size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, (size > old_size) ? old_size : size);
	free(ptr);
	return (new_ptr);
}
