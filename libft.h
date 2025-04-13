/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordanschillereff <jordanschillereff@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:33:40 by jleal             #+#    #+#             */
/*   Updated: 2025/04/13 14:07:16 by jordanschil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// libc01.c
int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

// libc02.c
size_t	ft_strlen(const char *str);

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

// libc03.c
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	ft_toupper(char c);

char	ft_tolower(char c);

char	*ft_strchr(const char *s, int c);

// libc04.c
char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// libc05.c
int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

char	**ft_split(const char *str, char c);

#endif