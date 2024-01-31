/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:14:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*castS;
	unsigned char	*castD;
	size_t	i;

	i = 0;
	castS = src;
	castD = dst;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		castD[i] = castS[i];
		i++;	
	}
	return (dst = castD);
}
