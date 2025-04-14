/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:12:37 by jordanschil       #+#    #+#             */
/*   Updated: 2025/04/14 11:35:43 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_intl(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	i = 0;
	if (n == 0)
		return (1);
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
	str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memcpy(str, &"-2147483648", 11);
		return (str);
	}
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