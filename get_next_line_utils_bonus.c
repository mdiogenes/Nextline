/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:45:36 by msoler-e          #+#    #+#             */
/*   Updated: 2022/02/21 09:45:46 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	cont;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	cont = 0;
	while (str[i] != '\0')
	{
		cont ++;
		i++;
	}
	return (cont);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dst;
	int				x;
	int				y;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc(sizeof (const char) * (ft_strlen((char *)s1))
			+ (ft_strlen((char *)s2)) + 1);
	if (dst == 0)
		return (0);
	x = -1;
	while (s1[++x] != '\0')
		dst[x] = s1[x];
	y = 0;
	while (s2[y] != '\0')
			dst[x++] = s2[y++];
	dst[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strchr(char *str, int c)
{
	size_t	x;

	x = 0;
	if (!str)
		return (NULL);
	while (str[x] != (char)c)
	{
		if (str[x] == '\0' && (char)c != '\0')
			return (NULL);
		x++;
	}
	return ((char *)&str[x]);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	temp;

	if (!s)
		return (NULL);
	temp = 0;
	if (start >= ft_strlen(s))
		dst = malloc(sizeof(char));
	else if (ft_strlen(s) - start < len)
		dst = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (start + temp < ft_strlen(s) && temp < len)
	{
		dst[temp] = s[start + temp];
		temp++;
	}
	dst[temp] = '\0';
	return (dst);
}
