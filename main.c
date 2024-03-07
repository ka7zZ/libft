/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:01:22 by aghergut          #+#    #+#             */
/*   Updated: 2024/03/07 17:29:02 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

void	my_tolower(unsigned int i, char *str)
{
	char	ch;

	ch = str[i];
	str[i] = ft_tolower(ch);
}

char	mapi_func(unsigned int i, char ch)
{
	ch += i;
	return (ch);
}

void	free_content(void *content)
{
	free(content);
}

void	show_list(t_list *lst)
{
	t_list	*ptr;
	int		i;

	i = 1;
	ptr = lst;
	while (ptr != NULL)
	{
		printf("%d\t%s\n", i, ptr->content);
		i++;
		ptr = ptr->next;
	}
}

void	show_node(t_list *node)
{
	printf("\nAddress: %p\nContent: %s\n\n", &node, node->content);
}

void	do_lstiter(void *str)
{
	int		i;
	char	*temp;

	if (str)
	{
		i = 0;
		temp = (char *)str;
		while (temp[i] != 0)
		{
			while (temp[i] == ' ')
				i++;
			temp[i] = temp[i] - 32;
			i++;
		}
		str = temp;
	}
}

void	*do_lstmap(void *str)
{
	int		i;
	char	*temp;

	if (str)
	{
		i = 0;
		temp = (char *)str;
		while (*temp)
		{
			while (*temp == ' ')
				temp++;
			if (*temp >= 'A' && *temp <= 'Z')
				temp += 32;
			temp++;
		}
		str = temp;
		return (str);
	}
	return (NULL);
}

t_list	*return_node(t_list	*lst, int n)
{
	t_list	*ptr;
	int		i;

	if (lst)
	{
		i = 1;
		while (lst != NULL)
		{
			if (i == n)
			{
				ptr = lst;
				return (ptr);
			}
			i++;
			lst = lst->next;
		}
	}
	return (NULL);
}

int	main(int argsc, char **argsv)
{
	int		i;
	int		j;
	int		mem;
	int		test_int;
	int		file;
	int		*input;
	char	test_char;
	char	ch;
	char	*test_string;
	char	*test_string2;
	char	*test_func;
	char	*input_function;
	char	**split_case;
	t_list	*lst;
	t_list	*node;

	if (argsc < 2)
		return (1);
	input_function = argsv[1];
	if (strcmp(input_function, "ft_atoi") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		printf("Number is: %d\n", test_int);
	}
	else if (strcmp(input_function, "ft_bzero") == 0)
	{
		test_string = argsv[2];
		printf("String: '%s'", test_string);
		ft_bzero(test_string, ft_strlen(test_string));
		printf("is now: '%s' (null setted).\n", test_string);
	}
	else if (strcmp(input_function, "ft_calloc") == 0)
	{
		i = 0;
		test_string = (char *) ft_calloc(ft_atoi(argsv[2]), ft_atoi(argsv[3]));
		while (i < ft_atoi(argsv[2]))
		{
			test_string[i] = i + 'a';
			i++;
		}
		printf("Result: %s\n", test_string);
	}
	else if (strcmp(input_function, "ft_isalnum") == 0)
	{
		test_char = argsv[2][0];
		if (ft_isalnum((int) test_char) == 1)
			printf("The char '%c' is alphanumeric character\n", test_char);
		else
			printf("The char '%c' is not alphanumeric character\n", test_char);
	}
	else if (strcmp(input_function, "ft_isalpha") == 0)
	{
		test_char = argsv[2][0];
		if (ft_isalpha((int) test_char) == 1)
			printf("The char '%c' is an alphabetical character\n", test_char);
		else
			printf("The char '%c' is not an alphabetical character\n", test_char);
	}
	else if (strcmp(input_function, "ft_isascii") == 0)
	{
		test_char = argsv[2][0];
		if (ft_isascii((int) test_char) == 1)
			printf("The char '%c' is withing ASCII table\n", test_char);
		else
			printf("The char '%c' is not withing ASCII table\n", test_char);
	}
	else if (strcmp(input_function, "ft_isdigit") == 0)
	{
		test_char = argsv[2][0];
		if (ft_isdigit((int) test_char) == 1)
			printf("The char '%c' is a number\n", test_char);
		else
			printf("The char '%c' is not number\n", test_char);
	}
	else if (strcmp(input_function, "ft_isprint") == 0)
	{
		test_char = argsv[2][0];
		if (ft_isprint((int) test_char) == 1)
			printf("The char '%c' is printable\n", test_char);
		else
			printf("The char '%c' is not printable\n", test_char);
	}
	else if (strcmp(input_function, "ft_itoa") == 0)
	{
		test_int = ft_atoi(argsv[2]);
		test_string = ft_itoa(test_int);
		printf("The number %d successfully converted into string -> %s\n", test_int, test_string);
	}
	else if (strcmp(input_function, "ft_memchr") == 0)
	{
		test_string = argsv[2];
		test_char = argsv[3][0];
		mem = argsv[3][0];
		test_int = ft_atoi(argsv[4]);
		printf("String: %s\nChar: %c\nSize: %d\n\n", test_string, test_char, test_int);
		printf("infunc: %p\n", memchr(test_string, mem, test_int));
		printf("myfunc: %p\n", ft_memchr(test_string, mem, test_int));
	}
	else if (strcmp(input_function, "ft_memcmp") == 0)
	{
		mem = ft_atoi(argsv[4]);
		printf("String 1: %s\nString 2: %s\n\n", argsv[2], argsv[3]);
		printf("infunc: %d\n", memcmp(argsv[2], argsv[3], mem));
		printf("myfunc: %d\n", ft_memcmp(argsv[2], argsv[3], mem));
	}
	else if (strcmp(input_function, "ft_memcpy") == 0)
	{
		test_int = ft_atoi(argsv[4]);
		test_string = argsv[2];
		test_string2 = argsv[2];
		test_func = argsv[3];
		printf("Destination string: %s\nSource string: %s\nLength to copy: %d\n\n", test_string, test_func, test_int);
		memcpy(test_string, test_func, test_int);
		ft_memcpy(test_string2, test_func, test_int);
		printf("infunc: %s\nmyfunc: %s\n", test_string, test_string2);
	}
	else if (strcmp(input_function, "ft_memmove") == 0)
	{
		test_int = ft_atoi(argsv[4]);
		test_string = argsv[2];
		test_string2 = argsv[2];
		test_func = argsv[3];
		printf("Destination string: %s\nSource string: %s\nLength to copy: %d\n\n", test_string, test_func, test_int);
		memmove(test_string, test_func, test_int);
		ft_memmove(test_string2, test_func, test_int);
		printf("infunc: %s\nmyfunc: %s\n", test_string, test_string2);
	}
	else if (strcmp(input_function, "ft_memset") == 0)
	{
		test_char = argsv[3][0];
		test_int = ft_atoi(argsv[4]);
		test_string = argsv[2];
		test_string2 = argsv[2];
		printf("String: %s\nChar: %c\nSize: %d\n\n", test_string, test_char, test_int);
		ft_memset(test_string, test_char, test_int);
		memset(test_string2, test_char, test_int);
		printf("infunc: %s\nmyfunc: %s\n", test_string2, test_string);
	}
	else if (strcmp(input_function, "ft_putchar_fd") == 0)
	{
		if (argsv[2])
		{
			test_char = argsv[2][0];
			file = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
			if (file == -1)
				printf("Error creating the file\n");
			ft_putchar_fd(test_char, file);
		}
		else
			printf("Not input, not result!\n");
	}
	else if (strcmp(input_function, "ft_putstr_fd") == 0)
	{
		if (argsv[2])
		{
			test_string = argsv[2];
			file = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putstr_fd(test_string, file);
		}
		else
			printf("Not input, not result!\n");
	}
	else if (strcmp(input_function, "ft_putendl_fd") == 0)
	{
		if (argsv[2])
		{
			file = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putendl_fd(argsv[2], file);
		}
		else
			printf("Not input, not result!\n");
	}
	else if (strcmp(input_function, "ft_putnbr_fd") == 0)
	{
		if (argsv[2])
		{
			test_int = ft_atoi(argsv[2]);
			file = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
			if (file == -1)
				printf("Error creating the file");
			ft_putnbr_fd(test_int, file);
		}
		else
			printf("Not input, not result!\n");
	}
	else if (strcmp(input_function, "ft_split") == 0)
	{
		test_char = argsv[3][0];
		test_string = argsv[2];
		split_case = ft_split(test_string, test_char);
		if (!split_case)
			return (0);
		i = 0;
		while (split_case[i] != NULL)
		{
			printf("%d) %s\n", i + 1, split_case[i]);
			i++;
		}
		free(split_case);
		return (0);
	}
	else if (strcmp(input_function, "ft_strchr") == 0)
	{
		test_char = argsv[3][0];
		test_string = argsv[2];
		printf("String: %s\nChar: %c\n\n", test_string, test_char);
		test_func = strchr(test_string, test_char);
		printf("infunc: %s\n", test_func);
		test_string2 = ft_strchr(test_string, test_char);
		printf("myfunc: %s\n", test_string2);
	}
	else if (strcmp(input_function, "ft_strdup") == 0)
	{
		test_string = argsv[2];
		printf("String: %s\n", test_string);
		test_string2 = ft_strdup(test_string);
		printf("Result of duplication: %s\n", test_string2);
	}
	else if (strcmp(input_function, "ft_strjoin") == 0)
	{
		test_string = ft_strjoin(argsv[2], argsv[3]);
		printf("String1: %s\nString2: %s\n\nResult: %s\n", argsv[2], argsv[3], test_string);
	}
	else if (strcmp(input_function, "ft_strlcat") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_string = argsv[2];
		test_func = argsv[3];
		printf("String1: %s\nString2: %s\n\n", test_string, test_func);
		test_int = ft_strlcat(test_string, test_func, mem);
		printf("myfunc:\nResult return strlcat: %d\n", test_int);
		ft_strlcat(test_string, test_func, mem);
		printf("Result destination string: %s\n", test_string);
	}
	else if (strcmp(input_function, "ft_strlcpy") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_string = argsv[2];
		printf("Trying to copy %d chars from %s into a new variable ...\n", mem, (char *) argsv[3]);
		test_int = ft_strlcpy(test_string, argsv[3], mem);
		ft_strlcpy(test_string, argsv[3], mem);
		printf("Result return strlcpy: %d\n", test_int);
		printf("Result of the new variable: %s\n", test_string);
	}
	else if (strcmp(input_function, "ft_strlen") == 0)
	{
		test_string = argsv[2];
		printf("The length of %s is: %ld\n", test_string, ft_strlen(test_string));
	}
	else if (strcmp(input_function, "ft_strncmp") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_int = ft_strncmp(argsv[2], argsv[3], mem);
		printf("The result of comparing '%s' with '%s' is: %d\n", argsv[2], argsv[3], test_int);
	}
	else if (strcmp(input_function, "ft_strnstr") == 0)
	{
		mem = ft_atoi(argsv[4]);
		test_string = ft_strnstr(argsv[2], argsv[3], mem);
		printf("Haystack: %s\nNeedle: %s\n\nResult: %s\n", argsv[2], argsv[3], test_string);
	}
	else if (strcmp(input_function, "ft_strrchr") == 0)
	{
		test_char = argsv[3][0];
		test_string = ft_strrchr(argsv[2], test_char);
		printf("String: %s\nChar: %c\n\nResult: %s\n", argsv[2], test_char, test_string);
	}
	else if (strcmp(input_function, "ft_strtrim") == 0)
	{
		test_string = argsv[2];
		test_func = argsv[3];
		printf("String: %s\nSequence: %s\n\nResult: %s\n", test_string, test_func, ft_strtrim(test_string, test_func));
	}
	else if (strcmp(input_function, "ft_substr") == 0)
	{
		i = ft_atoi(argsv[3]);
		j = ft_atoi(argsv[4]);
		test_string = ft_substr(argsv[2], i, j);
		printf("String: %s\nFrom: [%d]\nLength: %d\n\nResult: %s\n", argsv[2], i, j, test_string);
	}
	else if (strcmp(input_function, "ft_tolower") == 0)
	{
		test_char = argsv[2][0];
		ch = ft_tolower(test_char);
		printf("Char: %c\n\nResult: %c\n", test_char, ch);
	}
	else if (strcmp(input_function, "ft_toupper") == 0)
	{
		test_char = argsv[2][0];
		ch = ft_toupper(test_char);
		printf("Char: %c\n\nResult: %c\n", test_char, ch);
	}
	else if (strcmp(input_function, "ft_striteri") == 0)
	{
		test_string = argsv[2];
		ft_striteri(test_string, my_tolower);
		printf("%s\n", test_string);
	} 
	else if (strcmp(input_function, "ft_strmapi") == 0)
	{
		test_string = argsv[2];
		printf("Input string: %s\n\nResult: %s\n", test_string, ft_strmapi(test_string, mapi_func));
	}
	else if (strcmp(input_function, "ft_lstnew") == 0)
	{
		
		//lstnew
		lst = ft_lstnew(ft_strdup(argsv[2]));
		show_list(lst);
		printf("Enter a content for adding it to a node in the front of the list:\n-$>:  ");
		test_string = malloc(255 * sizeof(char));
		scanf("%s", test_string);
		node = ft_lstnew(ft_strdup(test_string));
		
		//add_front
		ft_lstadd_front(&lst, node);
		
		//lstsize
		free(test_string);
		printf("\nThe size of our list is: %d nodes\n\n", ft_lstsize(lst));
		show_list(lst);
		
		//add_back
		printf("We are adding here some nodes... Wanna contribute? (1-yes 2-no)\n-$>: ");
		input = malloc(1 * sizeof(int));
		scanf("%d", input);
		if (input[0] == 1)
		{
			printf("Press 2 to exit\n");
			while (true)
			{
				test_string2 = malloc(255 * sizeof(char));
				printf("\nAdd content: ");
				scanf("%s", test_string2);
				test_int = ft_atoi(test_string2);
				if (test_int == 2)
				{
					break;
				}
				node = ft_lstnew(ft_strdup(test_string2));
				ft_lstadd_back(&lst, node);
				free(test_string2);
			}
		}
		else
		{
			test_string = malloc(255 * sizeof(char));
			test_string = "add_back1&add_back2&add_back3";
			split_case = ft_split(test_string, '&');
			i = 0;
			while (split_case[i] != NULL)
			{
				node = ft_lstnew(ft_strdup(split_case[i]));
				show_node(node);
				ft_lstadd_back(&lst, node);
				i++;
			}
		}
		show_list(lst);
		free(input);
		input = malloc(1 * sizeof(int));
		
		//delone
		printf("Which node do you want to delete?\n-$>: ");
		scanf("%d", input);
		node = return_node(lst, input[0]);
 		printf("This is the node that will be deleted: \n");
		show_node(node);
		ft_lstdelone(node, free_content);
		printf("\nNew list: \n\n");
		show_list(lst);
		
		//lstlast
		node = ft_lstlast(lst);
		printf("\n\nThe last node is: \n");
		show_node(node);
		
		//lstiter
		printf("lstiter with a function that capitalize the content will be like this: ");
		ft_lstiter(node, do_lstiter);
		show_node(node);
		
		//lstmap
		printf("\n\nAnd lstmap will look like this: \n");
		node = ft_lstmap(lst, do_lstmap, free_content);
		show_list(node);
		
		//lstclear
		printf("\n\nFinally we should clear the list.");
		ft_lstclear(&node, free_content);
		ft_lstclear(&lst, free_content);
		printf("New content is: \n");
		show_list(lst);
	}
	else
		printf("Unkown option %s. Not in the lib\n", argsv[1]);
}
