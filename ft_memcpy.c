/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:29 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:14:11 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*castD;
	unsigned char	*castS;
	size_t		i;

	if (src == NULL)
		return (NULL);
	castD = (unsigned char *)dst;
	castS = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		castD[i] = castS[i];
		i++;
	}
	return (dst = castD);
}