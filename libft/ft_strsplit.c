/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:55:22 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/07 15:41:43 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdcount(char const *s, char c)
{
	int		wd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wd = 0;
	while (s[i] != '\0')
	{
		if (j == 1 && s[i] == c)
			j = 0;
		if (j == 0 && s[i] != c)
		{
			j = 1;
			wd++;
		}
		i++;
	}
	return (wd);
}

static int	ft_wdlen(char const *s, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		wdcount;
	int		i;
	int		i2;

	if (s == NULL || !c)
		return (0);
	i = 0;
	i2 = 0;
	wdcount = ft_wdcount((const char *)s, c);
	str = (char **)malloc(sizeof(*str) * (wdcount + 1));
	if (str == NULL)
		return (NULL);
	while (i2 < wdcount)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i2] = ft_strsub((const char *)s, 0, ft_wdlen((const char *)s, c));
		if (str[i2] == NULL)
			return (NULL);
		s = s + ft_wdlen((const char *)s, c);
		i2++;
	}
	str[i2] = NULL;
	return (str);
}
