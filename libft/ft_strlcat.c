/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:22:31 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/04 14:06:33 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int	i;
	int	c;
	int	max;

	max = 0;
	i = ft_strlen(dst);
	c = ft_strlen((char *)src);
	max = i;
	if (i > (int)n)
		max = n;
	max = max + c;
	c = 0;
	while ((i + c) < ((int)n - 1) && src[c] != '\0')
	{
		dst[i + c] = src[c];
		c++;
	}
	dst[i + c] = '\0';
	return (max);
}
