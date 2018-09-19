/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:19:18 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/18 14:22:03 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(size_t i, char *s1)
{
	while (s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t')
		i++;
	return (i);
}

static size_t	jcounter(size_t i, char *s1)
{
	while (s1[i] != '\0')
		i++;
	i--;
	while (s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*s2;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL)
		return (0);
	i = counter(i, (char *)s1);
	if (s1[i] == '\0')
		return (ft_strcpy((char *)malloc(sizeof(char) * 2), ""));
	j = jcounter(j, (char *)s1);
	s2 = (char *)malloc(sizeof(char) * (j - i + 2));
	if (s2 == NULL)
		return (NULL);
	while (k < j - i + 1)
	{
		s2[k] = s1[i + k];
		k++;
	}
	s2[k] = '\0';
	return (s2);
}
