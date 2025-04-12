/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:43:55 by jleal             #+#    #+#             */
/*   Updated: 2025/04/12 18:46:12 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c)
{
	char			a;
	char			*ptr;
	unsigned int	i;

	a = (char) c;
	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			ptr = (char *) &s[i];
		i++;
	}
	if (s[i] == a)
		ptr = (char *) &s[i];
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

// locate byte in byte string
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;

	ptr = (unsigned char *) s;
	a = (unsigned char) c;
	while (n-- > 0)
	{
		if (*ptr == a)
		{
			return ((void *)ptr);
		}
		ptr++;
	}
	return (NULL);
}

//compare two strings of bytes
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// Locate substring in a string 
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	needlelen;

	if (!needle)
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	while (*haystack && len-- > 0)
	{
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, needlelen))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
