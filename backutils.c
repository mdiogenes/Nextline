/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:55:00 by msoler-e          #+#    #+#             */
/*   Updated: 2022/02/09 15:29:09 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != (const char)c)
		i++;
	if (*(s + i) == (const char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_strlen((char *)s);
	if ((long)size - (long)start < 0)
		len = 0;
	else if (size - start < len)
		len = size - start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (*(str + size) != '\0')
		size++;
	return (size);
}
