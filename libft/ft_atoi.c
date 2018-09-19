/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:06:23 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/18 14:06:10 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conversion(const char *str, size_t i)
{
	size_t	j;
	size_t	multiplyer;
	int		returnvalue;

	j = i;
	multiplyer = 1;
	returnvalue = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		multiplyer = multiplyer * 10;
		i++;
	}
	multiplyer = multiplyer / 10;
	while (ft_isdigit(str[j]) == 1)
	{
		returnvalue = returnvalue + ((str[j] - 48) * multiplyer);
		multiplyer = multiplyer / 10;
		j++;
	}
	return (returnvalue);
}

int			ft_atoi(const char *str)
{
	size_t	neg;
	size_t	i;
	int		returnvalue;

	neg = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	returnvalue = conversion(str, i);
	returnvalue = returnvalue * neg;
	if (returnvalue > 2147483647 || returnvalue < ((2147483647 * -1) - 1))
		return (0);
	return (returnvalue);
}
