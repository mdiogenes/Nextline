/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:44:27 by msoler-e          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:41 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*update(char *temp)
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

char	*save(char *temp)
{
	char	*result;
	int		i;

	i = 0;
	if (!temp[0])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	i++;
	result = ft_substr(temp, 0, i);
	return (result);
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
	static char	*tmp[PATH_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > PATH_MAX)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = NULL;
	tmp[fd] = readline(fd, tmp[fd]);
	if (!tmp[fd] || !tmp[fd][0])
	{
		free(tmp[fd]);
		return (NULL);
	}
	result = save(tmp[fd]);
	tmp[fd] = update(tmp[fd]);
	return (result);
}
