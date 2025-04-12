/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:25:31 by jleal             #+#    #+#             */
/*   Updated: 2025/04/12 20:32:19 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_wrdlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(const char *s, char c)
{
	unsigned int	wrds;
	unsigned int	i;

	wrds = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			wrds++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wrds);
}

static void *ft_free(char **strs, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*make_word(char *str, char c)
{
	char	*ptr;
	int		len;

	while (*str == c)
		str++;
	printf("%s\n", str);
	len = ft_wrdlen(str, c);
	if (len == 0)
		return (NULL);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	printf("made it past NULL in make _word\n");
	ft_memcpy(ptr, str, len);
	return (ptr);
}

char **ft_split(const char *str, char c)
{
	char			**ptrs;
	unsigned int	i;
	unsigned int	wrds;

	wrds = count_words(str, c);
	ptrs = (char **)ft_calloc((wrds + 1), sizeof(char *));
	if (!ptrs)
		return (NULL);
	printf("past callocc");
	while (i < wrds && *str)
	{
		ptrs[i] = make_word((char *)str, c);
		if (!ptrs[i])
			return (ft_free(ptrs, wrds));
		printf("%s\n", ptrs[i]);
		while (*str && *str != c)
			str++;
		i++;
	}
	return (ptrs);
}

int main(void)
{
	char str[] = "   hello   world good bye  ";
	char **wrds;

	wrds = ft_split(str, ' ');
	printf("%s %s\n", wrds[0], wrds[3]);
}