/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 09:34:48 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/18 16:10:27 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_multi(int n)
{
	int			multi;

	multi = 1;
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			multi = multi * 10;
		}
		multi = multi / 10;
	}
	return (multi);
}

static int		ft_len(int n)
{
	int			len;

	len = 1;
	if (n > 0)
	{
		len = 0;
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static char		*conversion(int n, int neg, int len, char *str)
{
	int			i;
	int			multi;

	i = 0;
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	multi = ft_multi(n);
	while (len > 0)
	{
		str[i] = (n / multi) + 48;
		i++;
		n = n % multi;
		multi = multi / 10;
		len--;
	}
	str[i] = '\0';
	return (str);
}

static char		*is_0(char *str, int n, int i)
{
	if (n == 0 || n == -0)
	{
		str[i] = '0';
		i++;
		str[i] = '\0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			neg;
	int			len;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
		i++;
	}
	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return ("2147483647");
	str = (char *)malloc(sizeof(char ) * (i + len + 1));
	if (str == NULL)
		return (NULL);
	str = conversion(n, neg, len, str);
	str = is_0(str, n, i);
	return (str);
}
