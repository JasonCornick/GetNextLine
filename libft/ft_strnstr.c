/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:26:16 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/19 13:57:46 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *n, size_t len)
{
	char	*s;
	size_t	i;
	size_t	c;
	size_t	d;

	s = (char *)hay;
	i = 0;
	c = 0;
	d = 0;
	while (n[c] != '\0')
	{
		if (hay[i] == n[c])
			c++;
		else if (c > 0 && n[c] != '\0')
		{
			i = (i - i) + (d++);
			c = 0;
		}
		if (hay[i] == '\0')
			return (NULL);
		if (i == len)
			return (NULL);
		i++;
	}
	return (s + (i - c));
}
