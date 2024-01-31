/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:15:51 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 13:44:17 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *function(unsigned int idx, char c)
{
	char	*res;
	size_t	n;
	size_t	size;
	char	*index;
	int		i;
	
	n = 20;
	i = 0;
	size = sizeof(char);
	index = ft_itoa(idx);
	res = ft_calloc(n * size);
	while (index[i] != '\0')
		res[i++] = index[i++];
	res[i] = c;
	return (res);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char				*res;
	unsigned int		i;

	if (ft_strlen(s) <= 0)
		return (NULL);
	res = calloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++
	}
	res[i] = '\0';
	free(f);
	return (res);
}