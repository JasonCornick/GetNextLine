/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:02:03 by jcornick          #+#    #+#             */
/*   Updated: 2018/05/30 16:42:19 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *n)
{
	char	*s;
	int		i;
	int		c;
	int		d;

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
			i = (i - i) + (++d);
			c = 0;
		}
		else
			c = 0;
		if (hay[i] == '\0')
			return (NULL);
		i++;
	}
	return (s + (i - c));
}
