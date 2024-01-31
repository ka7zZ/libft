/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:41:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
    char    *res;
	int	i;
	int	last;

	res = (char *)str;
    i = 0;
	last = 0;
	while (res[i] != '\0')
	{
		if (res[i] == ch)
			last = i;
		i++;
	}
	if (last > 0)
		return (res + last);
	return (0);
}
