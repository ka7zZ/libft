/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:12 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/12 14:44:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = ft_calloc((int)len + 1, sizeof(char));
	if (substr != NULL)
	{
		if ((size_t)start >= ft_strlen(s) || (int)start < 0 || (int)len == 0)
			return (substr);
		if ((int)start == 0 && (int)len < 0)
		{
			substr = (char *) s;
			return (substr);
		}
		i = 0;
		start -= 1;
		while (i < len)
			substr[i++] = s[start++];
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
*/