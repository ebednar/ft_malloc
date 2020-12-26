/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocated_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:49:23 by rwalder-          #+#    #+#             */
/*   Updated: 2020/01/08 16:49:25 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t	get_zone_size(size_t size)
{
	size_t page_size;

	page_size = getpagesize();
	if ((size % page_size) == 0)
		return (size);
	size += page_size - (size % page_size);
	return (size);
}

t_zone			*add_zone(t_preallocated_zone *zone)
{
	t_zone *p;

	p = (t_zone *)MMAP(zone->min_alloc * sizeof(t_zone));
	ft_bzero(p, zone->min_alloc * sizeof(t_zone));
	p->size = 0;
	p->alloc_count = 0;
	if (zone->max_size != (size_t)(-1))
	{
		p->alloc_size = get_zone_size(zone->min_alloc * zone->max_size);
		p->zone = (void *)MMAP(p->alloc_size);
		ft_bzero(p->zone, zone->min_alloc * sizeof(t_zone));
		p->meta = MMAP(zone->min_alloc * (sizeof(t_alloc) + 1));
		ft_bzero(p->meta, zone->min_alloc * (sizeof(t_alloc) + 1));
	}
	return (p);
}

t_zone			*get_zone(t_preallocated_zone *zone, size_t size)
{
	t_zone *p;

	if (!zone->p_zone)
		zone->p_zone = add_zone(zone);
	p = zone->p_zone;
	while (p->next)
		p = p->next;
	if (size > (p->size - p->alloc_size) || p->alloc_count >= zone->min_alloc)
		p->next = add_zone(zone);
	return (p);
}

void			*get_address(t_zone *p_zone, size_t size)
{
	int		i;
	int		i_paste;
	void	*begin_addr;

	i = -1;
	begin_addr = p_zone->zone;
	while (++i < (int)p_zone->alloc_count &&
		(p_zone->meta[i].address - begin_addr + 1) < (long)size)
		begin_addr = p_zone->meta[i].address + p_zone->meta[i].size;
	p_zone->alloc_count++;
	i_paste = i--;
	while (++i < (int)p_zone->alloc_count - 1)
	{
		p_zone->meta[i + 1].address = p_zone->meta[i].address;
		p_zone->meta[i + 1].size = p_zone->meta[i].size;
	}
	p_zone->meta[i_paste].size = size;
	return (p_zone->meta[i_paste].address = begin_addr);
}

void			*alloc(t_preallocated_zone *zone, size_t size)
{
	t_zone *p_zone;

	p_zone = get_zone(zone, size);
	if (zone->max_size == (size_t)(-1))
	{
		p_zone->alloc_count = 1;
		p_zone->alloc_size = size;
		p_zone->size = size;
		p_zone->zone = MMAP(size);
		return (p_zone->zone);
	}
	p_zone->size += size;
	return (get_address(p_zone, size));
}
