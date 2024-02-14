/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:19:18 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/13 14:10:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(len * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	ft_bzero(res, len);
	res = ft_memcpy(res, s1, ft_strlen(s1));
	ft_strlcat(res, s2, len);
	return (res);
}
