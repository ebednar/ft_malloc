/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:48:37 by rwalder-          #+#    #+#             */
/*   Updated: 2020/10/29 14:48:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int	main(void)
{
	void *p;

	ft_putendl("Allocs:\n");
	malloc(10);
	p = malloc(20);
	malloc(30);
	show_alloc_mem();
	ft_putendl("\n----\nDelete middle section:\n");
	free(p);
	show_alloc_mem();
	ft_putendl("\n----\nNew alloc:\n");
	malloc(15);
	show_alloc_mem();
	return (0);
}
