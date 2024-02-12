/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:17:03 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/12 10:18:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	res = malloc(size * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (i < size)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
