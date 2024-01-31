/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:46:30 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:19:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int ft_atoi(char *s);
void	bzero(void *s, size_t n);
void	*calloc(size_t n, size_t size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char	*ft_itoa(int value);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char *str, char c);
char	*ft_strchr(const char *str, int ch);
char    *strdup(const char *src);
void ft_striteri(char *s, void (*f)(unsigned int, char*));
char    *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char	*dst, const char	*src, size_t size);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char    *function(unsigned int idx, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t n);
char	*ft_strrchr(const char *str, int ch);
char    *ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_tolower(int c);
int	ft_toupper(int c);

#endif