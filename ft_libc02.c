/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:34:58 by jleal             #+#    #+#             */
/*   Updated: 2025/04/17 16:38:36 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

// Returns the lenght of a string
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// Fill a bye string with a byte value
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char) c;
		len--;
	}
	return (b);
}

// Fill a byte string with zero
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}

// Copy memory area
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (src == (void *)0 && dst == (void *)0)
		return (dst);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	return (dst);
}

// Copy memory area while avoiding overwriting issues
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	i = 0;
	if (tmp_dst > tmp_src)
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	else
		while (i++ < len)
			tmp_dst[i] = tmp_src[i];
	return (dst);
}
