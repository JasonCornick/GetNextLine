/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:59:54 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/04 15:54:20 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	c1;

	i = 0;
	s = (unsigned char *)str;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == c1)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
