/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:48:37 by rwalder-          #+#    #+#             */
/*   Updated: 2020/10/11 14:48:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	reset_meta(t_zone *zone, int j)
{
	zone->meta[j].address = NULL;
	zone->meta[j].size = 0;
}

void		del_meta(t_zone *zone, void *address)
{
	int j;
	int del;

	j = -1;
	del = 0;
	while (++j < (int)zone->alloc_count)
	{
		if (zone->meta[j].address && address == zone->meta[j].address)
		{
			ft_bzero(zone->meta[j].address, zone->meta[j].size);
			zone->size -= zone->meta[j].size;
			zone->alloc_count--;
			del = 1;
			break ;
		}
	}
	if (!del)
		return ;
	while (j < (int)zone->alloc_count)
	{
		zone->meta[j].address = zone->meta[j + 1].address;
		zone->meta[j].size = zone->meta[j + 1].size;
		j++;
	}
	reset_meta(zone, j);
}

void		del_zone(t_preallocated_zone *conf, t_zone *zone)
{
	t_zone *p;
	t_zone *del_zone;

	p = conf->p_zone;
	if (p == zone)
	{
		conf->p_zone = (p->next) ? (p->next) : (NULL);
		munmap(p->zone, p->alloc_size);
		munmap(p->meta, conf->min_alloc * (sizeof(t_alloc) + 1));
		return ;
	}
	while (p->next && p->next != zone)
		p = p->next;
	if (!p->next)
		return ;
	del_zone = p->next;
	p->next = del_zone->next;
	munmap(del_zone->zone, del_zone->alloc_size);
	munmap(p->meta, conf->min_alloc * (sizeof(t_alloc) + 1));
}

static int	handle_zone(t_zone *zone, void *ptr, int i)
{
	if (g_preallocated_zones[i]->max_size == (size_t)(-1))
	{
		if (ptr != zone->zone)
			return (1);
		del_zone(g_preallocated_zones[i], zone);
	}
	else
	{
		del_meta(zone, ptr);
		if (zone->alloc_count == 0)
			del_zone(g_preallocated_zones[i], zone);
	}
	return (0);
}

void		free(void *ptr)
{
	int		i;
	t_zone	*zone;

	i = -1;
	pthread_mutex_lock(&g_mutex);
	while (g_preallocated_zones[++i])
	{
		if (!g_preallocated_zones[i]->p_zone)
			continue ;
		zone = g_preallocated_zones[i]->p_zone;
		while (zone)
		{
			if (ptr < zone->zone || ptr > (zone->zone + zone->alloc_size))
			{
				zone = zone->next;
				continue ;
			}
			if (handle_zone(zone, ptr, i))
				continue ;
			pthread_mutex_unlock(&g_mutex);
			return ;
		}
	}
	pthread_mutex_unlock(&g_mutex);
}
