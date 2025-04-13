/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordanschillereff <jordanschillereff@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:25:31 by jleal             #+#    #+#             */
/*   Updated: 2025/04/13 14:07:50 by jordanschil      ###   ########.fr       */
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

static void	*ft_free(char **strs, int count)
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

	len = ft_wrdlen(str, c);
	if (len == 0)
		return (NULL);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, len);
	return (ptr);
}

char	**ft_split(const char *str, char c)
{
	char			**ptrs;
	unsigned int	i;
	unsigned int	j;
	unsigned int	wrds;

	wrds = count_words(str, c);
	ptrs = (char **)ft_calloc((wrds + 1), sizeof(char *));
	if (!ptrs)
		return (NULL);
	i = 0;
	j = 0;
	while (i < wrds && str[j])
	{
		while(str[j] == c)
			j++;
		ptrs[i] = make_word((char *)&str[j], c);
		if (!ptrs[i])
			return (ft_free(ptrs, wrds));
		while (str[j] && str[j] != c)
			j++;
		i++;
	}
	return (ptrs);
}

/* int main(void)
{
	char str[] = "hello   wor ld good bye  ";
	char **wrds;
	int i = 0;

	wrds = ft_split(str, ' ');
	while (wrds[i])
	{
		printf("%s\n", wrds[i]);
		i++;
	}
	ft_free(wrds, i);
} */