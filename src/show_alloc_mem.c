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

static void		format_print(void *p_begin, void *p_end, size_t size)
{
	print_address(p_begin);
	ft_putstr(" - ");
	print_address(p_end);
	ft_putstr(": ");
	ft_putnbr_ul(size);
	ft_putendl(" bytes");
}

static size_t	print_zone(t_preallocated_zone *conf, t_zone *zone)
{
	int		j;
	size_t	total;

	j = -1;
	total = 0;
	while (++j < (int)conf->min_alloc)
	{
		if (zone->meta[j].address)
		{
			format_print(zone->meta[j].address, zone->meta[j].address +
			zone->meta[j].size - 1, zone->meta[j].size);
			total += zone->meta[j].size;
		}
	}
	return (total);
}

static void		print_total(size_t total)
{
	ft_putstr("Total: ");
	ft_putnbr_ul(total);
	ft_putendl(" bytes");
}

void			show_alloc_mem(void)
{
	int		i;
	t_zone	*zone;
	size_t	total;

	i = -1;
	total = 0;
	pthread_mutex_lock(&g_mutex);
	while (g_preallocated_zones[++i])
	{
		ft_putstr(g_preallocated_zones[i]->name);
		ft_putendl(":");
		zone = g_preallocated_zones[i]->p_zone;
		while (zone && zone->alloc_size)
		{
			if (g_preallocated_zones[i]->max_size == (size_t)(-1))
				format_print(zone->zone, zone->zone + zone->size - 1,
					zone->size);
			else
				print_zone(g_preallocated_zones[i], zone);
			total += zone->size;
			zone = zone->next;
		}
	}
	print_total(total);
	pthread_mutex_unlock(&g_mutex);
}
