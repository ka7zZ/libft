/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:18:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/16 14:29:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	back_times(char const *s1, char const *set, int s1_len, int set_len)
{
	int	test;

	test = 0;
	while (s1_len >= 0)
	{
		while (set[set_len] == s1[s1_len])
		{
			test++;
			s1_len--;
			set_len--;
		}
		set_len = ft_strlen(set) - 1;
		if (s1[s1_len] != set[set_len])
			s1_len = -1;
	}
	test = test / ft_strlen(set);
	return (test);
}

static int	front_times(char const *s1, char const *set, int s1_i, int set_i)
{
	int	test;
	int	s1_len;

	test = 0;
	s1_len = ft_strlen(s1);
	while (s1_len >= 0)
	{
		while (set[set_i] == s1[s1_i])
		{
			test++;
			s1_i++;
			set_i++;
		}
		set_i = 0;
		if (s1[s1_i] != set[set_i])
			s1_len = -1;
	}
	test = test / ft_strlen(set);
	return (test);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		front_idx;
	int		back_idx;
	int		temp;

	front_idx = front_times(s1, set, 0, 0) * (int) ft_strlen(set);
	temp = back_times(s1, set, (int) ft_strlen(s1), (int) ft_strlen(set));
	back_idx = ft_strlen(s1) - temp * ft_strlen(set);
	temp = back_idx - front_idx;
	res = ft_substr(s1, front_idx, temp);
	if (res == NULL)
		return (NULL);
	return (res);
}
