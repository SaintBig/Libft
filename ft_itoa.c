/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:12:37 by jordanschil       #+#    #+#             */
/*   Updated: 2025/04/13 20:50:07 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_intl(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = ft_intl(n);
	printf("int len: %d\n", len);
	str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (len > i)
	{
		str[len - 1] = (n % 10) + '0';
		printf("in prog: %d\n", n % 10);
		len--;
		n /= 10;
	}
	return (str);
}

/* int main(void)
{
	int n = -1234;
	char *str;

	str = ft_itoa(n);
	printf("%s\n", str);
} */