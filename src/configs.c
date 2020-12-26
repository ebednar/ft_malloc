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

t_preallocated_zone g_tiny_zone =
{
	.name = "TINY",
	.max_size = 128,
	.min_alloc = 1024,
	.p_zone = NULL,
};

t_preallocated_zone g_small_zone =
{
	.name = "SMALL",
	.max_size = 1024,
	.min_alloc = 1024,
	.p_zone = NULL,
};

t_preallocated_zone g_large_zone =
{
	.name = "LARGE",
	.max_size = (size_t)(-1),
	.min_alloc = 1,
	.p_zone = NULL,
};

t_preallocated_zone *g_preallocated_zones[] =
{
	&g_tiny_zone,
	&g_small_zone,
	&g_large_zone,
	NULL,
};

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
