/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:31:15 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/21 18:16:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	v_length(int value)
{
	int	len;

	len = 1;
	if (value < 10)
		return (len);
	while (value > 9)
	{
		value /= 10;
		len++;
	}
	return (len);
}

char	*v_str(int len, int value, int kind)
{
	char	*number;

	if (kind == 0)
		number = ft_calloc((len + 2), sizeof(char));
	else
	{
		number = ft_calloc((len + 1), sizeof(char));
		len--;
	}
	if (!number)
		return (0);
	while (len >= 0)
	{
		if (len == 0 && kind == 0)
		{
			number[len] = '-';
			return (number);
		}
		number[len] = (value % 10) + '0';
		value /= 10;
		len--;
	}
	return (number);
}

char	*v_min(int len, int value)
{
	char	*min;

	min = calloc(12, sizeof(char));
	if (!min)
		return (0);
	min = v_str(len, value, 0);
	min[len] = '8';
	return (min);
}

char	*ft_itoa(int value)
{
	if (value == -2147483648)
	{
		value = (value + 1) * -1;
		return (v_min(v_length(value), value));
	}
	if (value < 0)
	{
		value *= -1;
		return (v_str(v_length(value), value, 0));
	}
	return (v_str(v_length(value), value, 1));
}
