/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:48:37 by rwalder-          #+#    #+#             */
/*   Updated: 2020/11/29 14:48:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int	main(void)
{
	void *p;

	p = malloc(64);
	ft_strcpy((char*)p, "TINY zone dump");
	p = malloc(2048);
	ft_strcpy((char*)p, "SMALL zone dump");
	p = malloc(5000);
	ft_strcpy((char*)p, "LARGE zone dump");
	show_alloc_mem_ex();
	return (0);
}
