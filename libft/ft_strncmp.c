/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:11:02 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/04 16:01:54 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int				i;
	int				v;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	v = n;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || i == (v - 1))
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
