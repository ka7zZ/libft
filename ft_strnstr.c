/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:18:29 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < n)
	{
		while (needle[j] != '\0' && needle[j] == haystack[i + j])
			j++;
		if (j == 0)
			return (haystack);
		else if (needle[j] == '\0')
			return (haystack + i);
		else
			j = 0;
		i++;
	}
	return (0);
}
