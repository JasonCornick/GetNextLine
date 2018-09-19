/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:31:48 by jcornick          #+#    #+#             */
/*   Updated: 2018/06/28 11:11:23 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_readline(int fd, char **prefix)
{
	char		*buff;
	char		*temp;
	int			bytesread;

	if (!(buff = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	bytesread = read(fd, buff, BUFF_SIZE);
	if (bytesread > 0)
	{
		buff[bytesread] = '\0';
		temp = ft_strjoin(*prefix, buff);
		if (!temp)
			return (-1);
		free(*prefix);
		*prefix = temp;
	}
	free(buff);
	return (bytesread);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*endline;
	int			bytesread;

	if ((!str && (str = ft_strnew(sizeof(*str))) == NULL) || !line)
		return (-1);
	while (!(endline = ft_strchr(str, '\n')))
	{
		if ((bytesread = ft_readline(fd, &str)) == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (bytesread < 0)
			return (-1);
		else
			endline = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(endline));
	endline = ft_strdup(endline + 1);
	free(str);
	str = endline;
	return (1);
}
