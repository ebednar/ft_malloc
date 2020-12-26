/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:44:29 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *ret;
	t_list *prev;
	t_list *begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = f(lst);
	lst = lst->next;
	begin = ret;
	while (lst)
	{
		prev = ret;
		ret = f(lst);
		if (ret == NULL)
			return (NULL);
		prev->next = ret;
		lst = lst->next;
	}
	return (begin);
}
