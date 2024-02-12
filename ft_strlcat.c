/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:31:19 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/12 17:29:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst + len_src >= size)
		return (len_dst + len_src);
	ft_memcpy(dst + len_dst, src, len_src + 1);
	return (len_dst + len_src);
}
