/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/09 15:24:03 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	char	c;
	int		i;
	int		last;

	res = (char *) str;
	c = (char) ch;
	i = 0;
	last = 0;
	while (res[i] != '\0')
	{
		if (res[i] == c)
			last = i;
		i++;
	}
	if (last > 0)
		return (res + last);
	else if (res[i] == ch)
		return (res + i);
	return (NULL);
}
