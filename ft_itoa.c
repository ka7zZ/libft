/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:20 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/13 17:11:14 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	v_length(int value)
{
	int	len;
	int	temp;

	len = 1;
	if (value < 10)
		return (len);
	temp = value;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*negative(int len, int value)
{
	char	*number;

	number = ft_calloc((len + 2), sizeof(char));
	if (number == NULL)
		return (NULL);
	while (len > 0)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
		len--;
	}
	number[len] = '-';
	return (number);
}

char	*positive(int len, int value)
{
	char	*number;

	number = ft_calloc((len + 1), sizeof(char));
	if (number == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
		len--;
	}
	return (number);
}

char	*ft_itoa(int value)	
{
	int		len;
	int		kind;
	char	*min;

	if (value == -2147483648)
	{
		min = ft_calloc(12, sizeof(char));
		if (min == NULL)
			return (NULL);
		value = (value + 1) * -1;
		len = v_length(value);
		min = negative(len, value);
		min[len] = '8';
		return (min); 
	}
	kind = 1;
	if (value < 0)
	{
		kind = 0;
		value *= -1;
	}
	len = v_length(value);
	if (kind == 0)
		return (negative(len, value));
	return (positive(len, value));
}
