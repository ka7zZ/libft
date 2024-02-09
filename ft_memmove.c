/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/09 14:52:02 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cast_src;
	unsigned char	*cast_dst;
	size_t			i;

	i = 0;
	cast_src = (unsigned char *)src;
	cast_dst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst = cast_dst);
}
