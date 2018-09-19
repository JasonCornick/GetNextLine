/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:35:52 by jcornick          #+#    #+#             */
/*   Updated: 2018/05/30 11:06:27 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	int				w;
	unsigned char	*v;

	i = 0;
	w = n;
	v = str;
	while (i != w)
	{
		v[i] = c;
		i++;
	}
	return (v);
}
