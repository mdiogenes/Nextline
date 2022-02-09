/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:21 by msoler-e          #+#    #+#             */
/*   Updated: 2022/02/09 15:20:45 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*save(char *temp)
{
	char	*result;
	int		x;

	x = 0;
	if (!temp)
		return (NULL);
	while (temp[x] != '\n' && temp[x] != '\0')
		x ++;
	x ++;
	result = ft_substr(temp, 0, x);
	return (result);
}

static char	*update(char *temp)
{
	char	*str;
	int		x;

	x = 0;
	if (!temp[x])
		return (NULL);
	while (temp[x] != '\n' && temp[x] != '\0')
		x ++;
	x ++;
	str = ft_substr(temp, x, ft_strlen(temp) - x);
	free(temp);
		return (str);
}

static char	*readbuffer(int fd, char *temp)
{
	char	*bufer;
	int		i;

	bufer = (char *)malloc(sizeof(char)* (BUFFER_SIZE +1));
	if (!bufer)
		return (NULL);
	i = 1;
	while (!ft_strchr(temp, '\n') && i != 0)
	{
	i = read(fd, bufer, BUFFER_SIZE);
		if (i < 1)
		{
			free(bufer);
			return (temp);
		}
		bufer[i] = '\0';
		temp = ft_strjoin(temp, bufer);
	}
	free(bufer);
	return (temp);

	}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*temp;

	if (!fd || BUFFER_SIZE <= 0)
		return (0);
	
	temp = readbuffer(fd, temp);
	if ( !temp)
	{
		free(temp);
		return (NULL);
	}
	result = save(temp);
	temp = update(temp);
	return (result);
}
