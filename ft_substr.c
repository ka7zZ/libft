/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:12 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/02 01:03:19 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	int		res;

	substr = (char *) malloc(sizeof(char) * ((int) len - (int) start + 1));
	res = (int)len - (int)start;
	if (res > 0)
	{
		i = 0;
		while ((size_t)start < len)
		{
			substr[i] = s[start];
			i++;
			start++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (0);
}
