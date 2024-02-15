/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/15 14:03:55 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_arrays(char *str, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word++;
		if (i == (int)ft_strlen(str) - 1 && str[i] == c)
			word --;
		i++;
	}
	return (word);
}

static char	**assign(char **sp, int sp_i, char *s, char c, int f, int s_i)
{
	char	*cstr;

	cstr = s;
	while (*s != '\0')
	{
		if (*s == c && s_i == 0)
		{
			s++;
			s_i++;
			f++;
		}
		if (*s == c && s_i != (int)ft_strlen(cstr) - 1)
		{
			sp[sp_i] = ft_substr(s, f, s_i - f);
			f = s_i + 1;
			sp_i++;
		}
		s_i++;
		s++;
	}
	sp[sp_i] = ft_substr(s, f, s_i - f);
	return (sp);
}

char	**ft_split(char *str, char c)
{
	char	**splits;

	splits = (char **) ft_calloc((count_arrays(str, c) + 1), sizeof(char *));
	if (!splits)
		return (NULL);
	splits = assign(splits, 0, str, 0, 0, 0);
	return (splits);
}
