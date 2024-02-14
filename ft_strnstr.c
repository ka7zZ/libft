/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/13 11:50:29 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < n)
	{
		while (needle[j] != '\0' && needle[j] == haystack[i + j] && i + j < n)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		if (j > 0)
			return (NULL);
		j = 0;
		i++;
	}
	return (NULL);
}
