/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:12:36 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/04 15:10:04 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	char	*dst;
	char	*src;

	dst = (char *)destination;
	src = (char *)source;
	if (!source && !destination)
		return (0);
	if (destination >= source)
		while (n--)
		{
			dst[n] = src[n];
		}
	else
		ft_memcpy(destination, source, n);
	return (destination);
}
