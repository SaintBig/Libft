/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:12:37 by jordanschil       #+#    #+#             */
/*   Updated: 2025/04/13 19:18:44 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int n)
{
	
}

int	ft_intl(int n)
{
	int i;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int main(void)
{
	printf("%d\n", ft_intl(12345));
}