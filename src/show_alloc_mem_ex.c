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

static void	print_hex(unsigned char value)
{
	char	hex[3];
	int		i;

	i = -1;
	while (++i < 3)
		hex[i] = 0;
	symtohex(value, (void*)&hex, 2);
	ft_putstr(hex);
	ft_putstr(" ");
}

static void	print_head(void *p_begin, void *p_end)
{
	print_address(p_begin);
	ft_putstr(" - ");
	print_address(p_end);
	ft_putstr(":   ");
}

static void	print_dump(unsigned char *begin, size_t size, int legnth)
{
	int j;
	int i;
	int size_group;

	j = 0;
	while (j < (int)size)
	{
		i = -1;
		size_group = ((int)(size - j) >= legnth) ? (legnth) : ((int)(size - j));
		print_head(begin + j, begin + j + size_group);
		while (++i < size_group)
			print_hex(*(begin + i + j));
		while (++i <= legnth + 1)
			ft_putstr("   ");
		i = -1;
		while (++i < size_group)
		{
			if (*(begin + i + j) >= ' ' && *(begin + i + j) <= '~')
				ft_putchar(*(begin + i + j));
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
		j += size_group;
	}
}

void		show_alloc_mem_ex(void)
{
	int		i;
	t_zone	*zone;

	i = -1;
	pthread_mutex_lock(&g_mutex);
	while (g_preallocated_zones[++i])
	{
		ft_putstr(g_preallocated_zones[i]->name);
		ft_putendl(":");
		zone = g_preallocated_zones[i]->p_zone;
		while (zone && zone->alloc_size)
		{
			print_dump(zone->zone, zone->size, 16);
			zone = zone->next;
		}
	}
	pthread_mutex_unlock(&g_mutex);
}
