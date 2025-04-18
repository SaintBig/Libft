/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:34:58 by jleal             #+#    #+#             */
/*   Updated: 2025/04/18 13:45:04 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the lenght of a string
size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
