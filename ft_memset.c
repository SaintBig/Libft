/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:16:09 by jleal             #+#    #+#             */
/*   Updated: 2025/04/18 10:34:01 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fill a bye string with a byte value
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;
	
	if (!b && len > 0)
		return (NULL);
	tmp_ptr = (unsigned char *) b;
	while (len--)
		*(tmp_ptr++) = (unsigned char) c;
	return (b);
}
