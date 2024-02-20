/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:32 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/20 13:12:48 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n)
		{	
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
  char haystack[30] = "aaabcabcd";
  char needle[10] = "aabc";
  printf("The myfunc string is: \n%s\n", ft_strnstr(haystack, needle, -1));
  //printf("The infunc string is: %s\n", strnstr(haystack, needle, -1));
  return (0);
}
*/
