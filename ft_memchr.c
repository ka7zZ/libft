/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:23 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/09 15:25:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == ch)
			return (res + i);
		i++;
	}
	return (0);
}
