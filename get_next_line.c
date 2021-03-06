/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:21 by msoler-e          #+#    #+#             */
/*   Updated: 2022/02/23 09:34:13 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*sobrantlinea(char *temp)
{
	char	*str;
	int		x;

	x = 0;
	if (!temp[x])
		return (NULL);
	while (temp[x] != '\n' && temp[x] != '\0')
		x++;
	x++;
	str = ft_substr(temp, x, ft_strlen(temp) - x);
	free(temp);
	return (str);
}

char	*readline(int fd, char *temp)
{
	char	*buffer;
	int		x;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	x = 1;
	while (!ft_strchr(temp, '\n') && x != 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 1)
		{
			free(buffer);
			return (temp);
		}
		buffer[x] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*tmp;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = readline(fd, tmp);
	if (!tmp || !tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	if (!tmp[0])
		return (NULL);
	x = 0;
	while (tmp[x] != '\n' && tmp[x] != '\0')
		x++;
	x++;
	result = ft_substr(tmp, 0, x);
	tmp = sobrantlinea(tmp);
	return (result);
}
