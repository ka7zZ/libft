/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:15:51 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/26 15:55:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	if (ft_strlen(s) <= 0)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
    if (!res)
    {
        return (NULL);
    }
    i = 0;
	while (*s)
	{
		res[i] = f(i, *s);
		i++;
        s++;
	}
	return (res);
}
