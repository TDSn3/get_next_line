/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:02:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/04/05 13:02:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] || (char)c == 0)
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i++;
		}
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	if (s)
		while (s[a])
			a++;
	return (a);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size)
		{
			dst[i] = src[i];
			i++;
		}
		if (size > ft_strlen(src))
			dst[i] = '\0';
		else
			dst[i - 1] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;

	s1s2 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1s2)
		return (NULL);
	ft_strlcpy(s1s2, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s1s2 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s1s2);
}
