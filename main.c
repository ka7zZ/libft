#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*my_tolower(unsigned int i, char *str)
{
	str[i] = str[i] + 32;
	return (str);
}

int main(int argsc, char **argsv)
{
	int		i;
	int		j;
	int		mem;
	int		test_int;
	int		file;
	char	test_char;
	char	ch;
	char	*test_string;
	char	*test_func;
	char	**split_case;

	if (argsc < 2)
	{
		printf("\nPlease insert correct input!\n");
		return (1);
	}
	printf("%d\n", argsc);
	i = 0;
	test_char = 0;
	test_func = NULL;
	test_int = 0;
	test_string = NULL;
	if (strcmp((char *) argsv[1], "ft_atoi") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		printf("%d\n", test_int);
	}
	else if (strcmp((char *) argsv[1], "ft_bzero") == 0)
	{
		test_func = (char *) argsv[2];
		test_string = (char *) argsv[2];
		ft_bzero(test_string, ft_strlen(test_string));
		printf("String: '%s' is now %s\n", test_func, test_string);
	}
	else if (strcmp((char *) argsv[1],"ft_calloc") == 0)
	{
		test_string = (char *) ft_calloc(ft_atoi(argsv[2]), ft_atoi(argsv[3]));
		while (i < ft_atoi(argsv[2]))
		{
			test_string[i] = i + 'a';
			i++;
		}
		printf("Result: %s\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_isalnum") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_char = (char) test_int;
		if (ft_isalnum(test_char) == 1)
			printf("The char '%c' is alphanumeric character\n", test_char);
		printf("The char '%c' is not alphanumeric character\n", test_char);
	}
	else if (strcmp((char *) argsv[1], "ft_isalpha") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_char = (char) test_int;
		if (ft_isalnum(test_char) == 1)
			printf("The char '%c' is an alphabetical character\n", test_char);
		printf("The char '%c' is not an alphabetical character\n", test_char);
	}
	else if (strcmp((char *) argsv[1], "ft_isascii") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_char = (char) test_int;
		if (ft_isalnum(test_char) == 1)
			printf("The char '%c' is withing ASCII table\n", test_char);
		printf("The char '%c' is not withing ASCII table\n", test_char);
	}
	else if (strcmp((char *) argsv[1], "ft_isdigit") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_char = (char) test_int;
		if (ft_isalnum(test_char) == 1)
			printf("The char '%c' is a number\n", test_char);
		printf("The char '%c' is not number\n", test_char);
	}
	else if (strcmp((char *) argsv[1], "ft_isprint") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_char = (char) test_int;
		if (ft_isalnum(test_char) == 1)
			printf("The char '%c' is printable\n", test_char);
		printf("The char '%c' is not printable\n", test_char);
	}
	else if (strcmp((char *) argsv[1], "ft_itoa") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_string = ft_itoa(test_int);
		printf("The number %d successfully converted into string -> %s\n", test_int, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_memchr") == 0)
	{
		test_string = (char *) argsv[2];
		mem = (char) ft_atoi(argsv[3]);
		test_int = ft_atoi(argsv[4]);
		printf("String: %s\nChar: %c\nSize: %d\n\n", test_string, test_char, test_int);
		ft_memchr(test_string, test_char, test_int);
		printf("Result: %s\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_memcmp") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_int = ft_memcmp(argsv[2], argsv[3], mem);
		printf("String 1: %s\nString 2: %s\n\nThe result of memcmp is: %d\n", argsv[2], argsv[3], test_int);
	}
	else if (strcmp((char *) argsv[1], "ft_memcpy") == 0)
	{
		test_int = ft_atoi(argsv[4]);
		test_string = ft_memcpy((char *) argsv[2], (char *) argsv[3], test_int);
		printf("String1: %s\nString2: %s\nSize: %d\n\nResult: %s\n", (char *) argsv[2], (char *) argsv[3], test_int, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_memmove") == 0)
	{
		test_int = ft_atoi(argsv[4]);
		test_string = ft_memmove(argsv[2], argsv[3], test_int);
		printf("String: %s\nString: %s\nSize: %d\n\nResult: %s\n", argsv[2], argsv[3], test_int, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_memset") == 0)
	{
		mem = ft_atoi(argsv[3]);
		test_char = (char) mem;
		test_int = ft_atoi(argsv[4]);
		test_string = ft_memset(argsv[2], test_char, test_int);
		printf("String: %s\nChar: %c\nSize: %d\n\nResult: %s\n", argsv[2], test_char, test_int, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_putchar_fd") == 0)
	{
		test_char = (char) ft_atoi(argsv[2]);
		if(ft_isalpha(test_char))
		{
			file = open("test.txt", O_CREAT | O_RDWR, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putchar_fd(test_char, file);
		}
		else
			printf("Wrong/Insufficient arguments");
	}
	else if (strcmp((char *) argsv[1], "ft_putstr_fd") == 0)
	{
		if(argsv[2])
		{
			file = open("test.txt", O_CREAT | O_RDWR, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putstr_fd(argsv[2], file);
		}
		else
			printf("Insufficient arguments");
	}
	else if (strcmp((char *) argsv[1], "ft_putendl_fd") == 0)
	{
		if (argsv[2])
		{
			file = open("test.txt", O_CREAT | O_RDWR, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putendl_fd(argsv[2], file);
		}
		else
			printf("Insufficient arguments");
	}
	else if (strcmp((char *) argsv[1], "ft_putnbr_fd") == 0)
	{
		if (argsv[2])
		{
			test_int = ft_atoi(argsv[2]);
			file = open("test.txt", O_CREAT | O_RDWR, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putnbr_fd(test_int, file);
		}
		else
			printf("Insufficient arguments");
	}
	else if (strcmp((char *) argsv[1], "ft_split") == 0)
	{
		test_char = (char) ft_atoi(argsv[3]);
		split_case = ft_split(argsv[2], test_char);
		if (!split_case)
			return (0);
		i = 0;
		while (*split_case)
		{
			j = 0;
			while (*split_case[j] != '\0')
				printf("%c", *split_case[j++]);
			printf("\n");
			i++;
			split_case++;
		}
	}
	else if (strcmp((char *) argsv[1], "ft_strchr") == 0)
	{
		test_char = (char) ft_atoi(argsv[3]);
		test_string = ft_strchr(argsv[2], test_char);
		printf("String: %s\nChar: %c\n\nResult: %s\n", argsv[2], test_char, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strdup") == 0)
	{
		test_string = ft_strdup(argsv[2]);
		printf("Result: %s\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strjoin") == 0)
	{
		test_string = ft_strjoin(argsv[2], argsv[3]);
		printf("String1: %s\nString2: %s\n\nResult: %s\n", argsv[2], argsv[3], test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strlcat") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_string = argsv[2];
		test_func = argsv[3];
		printf("String1: %s\nString2: %s\n\n", test_string, test_func);
		test_int = ft_strlcat(test_string, test_func, mem);
		printf("Result return strlcat: %d\n", test_int);
		printf("Result destination string: %s\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strlcpy") == 0)
	{
		mem = ft_atoi(argsv[4]);
		printf("Trying to copy %d chars from %s into a new variable!", mem, (char *) argsv[3]);
		test_int = ft_strlcpy((char *) argsv[2], (char *) argsv[3], mem);
		printf("Result return strlcpy: %d\n", test_int);
		printf("Result of the new variable: %s\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strlen") == 0)
	{
		test_string = argsv[2];
		printf("The length of %s is: %ld\n", test_string, ft_strlen(test_string));
	}
	else if (strcmp((char *) argsv[1], "ft_strncmp") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_int = ft_strncmp(argsv[2], argsv[3], mem);
		printf("The result of comparing '%s' with '%s' is: %d\n", argsv[2], argsv[3], test_int);
	}
	else if (strcmp((char *) argsv[1], "ft_strnstr") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_string = ft_strnstr(argsv[2], argsv[3], mem);
		printf("Haystack: %s\nNeedle: %s\n\nResult: %s\n", argsv[2], argsv[3], test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strrchr") == 0)
	{
		test_int = ft_atoi(argsv[3]);
		test_string = ft_strrchr((char *) argsv[2], test_int);
		printf("String: %s\nChar: %c\n\nResult: %s\n", argsv[2], test_int, test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_strtrim") == 0)
	{
		test_string = argsv[2];
		if (ft_strlen(argsv[3]) > 1)
		{
			test_func = argsv[3];
			printf("Trying to trimming '%s' of seq '%s'..\nResult: %s\n", test_string, test_func, ft_strtrim(test_string, test_func));
		}
		else
		{
			test_char = (char) ft_atoi(argsv[3]);
			printf("Trying to trimming '%s' of char '%c'..\nResult: %s\n", test_string, test_char, ft_strtrim(test_string, test_func));
		}
	}
	else if (strcmp((char *) argsv[1], "ft_substr") == 0)
	{
		i = ft_atoi(argsv[3]);
		j = ft_atoi(argsv[4]);
		test_string = ft_substr(argsv[2], i, j);
		printf("Trying to create a substring of '%s' starting from idx[%d]. The length should be %d characters", argsv[2], i, j);
		printf("The result is: '%s'\n", test_string);
	}
	else if (strcmp((char *) argsv[1], "ft_tolower") == 0)
	{
		test_char = (char) ft_atoi(argsv[2]);
		ch = ft_tolower(test_char);
		printf("Converting ...\n   ---- %c ----\n", ch);
	}
	else if (strcmp((char *) argsv[1], "ft_toupper") == 0)
	{
		test_char = (char) ft_toupper((char) ft_atoi(argsv[2]));
		printf("Converting ... \n---- %c ----\n", test_char);
	}
	else
		printf("Unkown option %s. Not in the lib\n", argsv[1]);
}
