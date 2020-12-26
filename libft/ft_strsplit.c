/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:33:14 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_symbol(const char *s, char c)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

static char		*ft_strsim(const char *s, char c)
{
	size_t	len;
	char	*ret;
	size_t	i;

	len = 0;
	ret = NULL;
	i = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	if (len != 0)
	{
		ret = (char*)malloc(sizeof(char) * (len + 1));
		if (ret != NULL)
		{
			while (i < len)
			{
				ret[i] = s[i];
				i++;
			}
			ret[i] = '\0';
		}
	}
	return (ret);
}

static char		**size0(char **p, char *s)
{
	p[0] = ft_strdup(s);
	p[1] = NULL;
	return (p);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	count;
	size_t	size;
	size_t	i;
	char	**ret;

	if (s == NULL)
		return (NULL);
	size = ft_number_symbol(s, c);
	if ((ret = (char**)malloc(sizeof(char*) * (size + 2))) == NULL)
		return (NULL);
	if ((size == 0) && (s[0] != '\0'))
		return (size0(ret, (char*)s));
	i = 0;
	count = 0;
	while (s[count] != '\0')
	{
		ret[i] = ft_strsim(s + count, c);
		if (ret[i] == NULL)
			count++;
		else
			count += (ft_strlen(ret[i++]));
	}
	ret[i] = NULL;
	return (ret);
}
