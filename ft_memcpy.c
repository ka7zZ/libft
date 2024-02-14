/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:29 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/13 09:57:07 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cast_dst;
	const unsigned char	*cast_src;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	cast_dst = (unsigned char *)dst;
	cast_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst = cast_dst);
}
