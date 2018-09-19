/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:33:40 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/01 15:41:29 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	char_c;
	char	*x;
	char	*b;

	i = 0;
	char_c = (unsigned char)c;
	x = dst;
	b = (char *)src;
	while (n > i)
	{
		if (b[i] == char_c)
		{
			x[i] = b[i];
			return (x + i + 1);
		}
		x[i] = b[i];
		i++;
	}
	return (0);
}
