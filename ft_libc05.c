/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc05.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:46:45 by jleal             #+#    #+#             */
/*   Updated: 2025/04/12 18:48:52 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	tot;
	int	p;
	int	i;

	tot = 0;
	p = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		p = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		tot = (tot * 10) + str[i] - '0';
		i++;
	}
	return (tot * p);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
