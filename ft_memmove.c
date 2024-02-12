/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/12 15:36:13 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*cast_src;
	char	*cast_dst;
	size_t	i;

	cast_src = (char *) src;
	cast_dst = (char *) dst;
	i = 0;
	if (cast_dst == NULL && src == NULL)
		return (NULL);
	if (cast_dst <= cast_src)
	{
		while (i < n)
		{
			cast_dst[i] = cast_src[i];
			i++;
		}
		return (dst);
	}
	else if (cast_dst > cast_src)
	{
		while (n-- > i)
			cast_dst[n] = cast_src[n];
		return (dst);
	}
	return (NULL);
}
