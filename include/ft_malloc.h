/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:48:37 by rwalder-          #+#    #+#             */
/*   Updated: 2020/01/08 14:48:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <stdbool.h>
# include <pthread.h>
# include "libft.h"

# define PROT_FLAGS (PROT_READ | PROT_WRITE)
# define MAP_FLAGS (MAP_ANON | MAP_PRIVATE)
# define MMAP(size) mmap(NULL, size, PROT_FLAGS, MAP_FLAGS, -1, 0)

typedef	struct				s_alloc
{
	void					*address;
	size_t					size;
}							t_alloc;

typedef struct				s_zone
{
	size_t					size;
	size_t					alloc_size;
	size_t					alloc_count;
	t_alloc					*meta;
	void					*zone;
	struct s_zone			*next;
}							t_zone;

typedef struct				s_preallocated_zone
{
	const char				*name;
	const size_t			max_size;
	const size_t			min_alloc;
	t_zone					*p_zone;
}							t_preallocated_zone;

extern t_preallocated_zone	*g_preallocated_zones[];
extern pthread_mutex_t		g_mutex;

void						show_alloc_mem(void);
void						free(void *ptr);
void						*malloc(size_t size);
void						*alloc(t_preallocated_zone *zone, size_t size);
void						ft_putnbr_ul(unsigned long n);
void						print_address(void *p);
void						symtohex(unsigned long long c, char *hex,
								unsigned int size);
void						*realloc(void *ptr, size_t size);
void						show_alloc_mem_ex(void);

#endif
