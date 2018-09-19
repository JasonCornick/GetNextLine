/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:13 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/06 14:20:40 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*rstr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	rstr = (char *)malloc(sizeof(char) *
			(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (rstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		rstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		rstr[i + j] = s2[j];
		j++;
	}
	rstr[i + j] = '\0';
	return (rstr);
}
