/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:12 by aghergut          #+#    #+#             */
/*   Updated: 2024/03/04 20:26:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s || ft_strlen(s) < start)
	{
		res = ft_calloc(1, sizeof(char));
		if (res == NULL)
			return (NULL);
		return (res);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (res);
	i = 0;
	while (start < ft_strlen((char *)s) && s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
