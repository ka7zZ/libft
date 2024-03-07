/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:26:17 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/28 17:10:51 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct node_list
{
	int					body_int;
	char				*content;
	struct node_list	*nodes;	
};

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = calloc(strlen(s) + 1, sizeof(char));
	if (!res)
	{
		free(res);
		return (0);
	}
	while (i < strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	show_node(struct node_list *node)
{
	struct node_list	**address;

	address = &node;
	printf("\nAddress: %p\nBody int: %d\nContent: %s\n\n", address, node->body_int, node->content);
}

void	show_list(struct node_list *lst)
{
	struct node_list	*ptr;
	int					i;

	i = 1;
	ptr = lst;
	while (ptr != NULL)
	{
		printf("%d.\t%d - %s\n", i, ptr->body_int, ptr->content);
		i++;
		ptr = ptr->nodes;
	}
}
int	struct_size(struct node_list *lst)
{
	int					count;
	struct node_list	*ptr;

	if (!lst)
		return (0);
	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->nodes;
	}
	return (count);
}

void	add_back(struct node_list **n1, struct node_list *new)
{
	struct node_list	*ptr;

	if (n1 && new)
	{
		ptr = *n1;
		while (ptr->nodes != NULL)
		{
			ptr = ptr->nodes;
		}
		ptr->nodes = new;
	}
}

void	add_front(struct node_list **n1, struct node_list *new)
{
	if (n1 && new)
	{
		new->nodes = *n1;
		*n1 = new;
	}
}

struct node_list	*return_last(struct node_list *lst)
{
	struct node_list	*ptr;
	struct node_list	*temp;

	if (!lst)
		return (NULL);
	ptr = (struct node_list *)malloc(sizeof(struct node_list));
	if (!ptr)
		return (0);
	temp = lst;
	while (temp != NULL)
	{
		ptr = temp;
		temp = temp->nodes;
	}
	return (ptr);
}

struct node_list	*return_node(struct node_list	*lst, int n)
{
	struct node_list	*ptr;
	int					i;

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
			lst = lst->nodes;
		}
	}
	return (NULL);
}

void	free_content(void *content)
{
	free(content);
}

void	del_node(struct node_list *node, void (*del)(void *))
{
	if (node)
	{		
		if (del)
			del(node->content);
		free(node);
	}	
}

void	skip_node(struct node_list **head, struct node_list *deleted)
{
	struct node_list	*current;
	
	if (!*head || !head || !deleted)
		return;
	current = *head;
	while (current->nodes != deleted)
	{
		if (current == NULL)
			return;
		current = current->nodes;
	}
	current->nodes = deleted->nodes;
}

void	struct_clear(struct node_list **head, void (*del)(void *))
{
	struct node_list	*ptr;
	struct node_list	*temp;

	if (*head || head || del)
	{
		ptr = *head;
		while (ptr->nodes != NULL)
		{
			temp = ptr;
			if (del != NULL)
				free_content(temp->content);
			ptr = ptr->nodes;
		}
		free(ptr);
		*head = NULL;
	}
}

void	do_something(void *str)
{
	int		i;
	char	*temp;

	if (str)
	{
		i = 0;
		temp = (char *)str;
		while(temp[i] != 0)
		{
			while (temp[i] == ' ')
				i++;
			temp[i] = temp[i] - 32;
			i++;
		}
		str = temp;
	}
}

void	*do_some(void *str)
{
	int		i;
	char	*temp;

	if (str)
	{
		i = 0;
		temp = (char *)str;
		while(temp[i] != 0)
		{
			while (temp[i] == ' ')
				i++;
			temp[i] = temp[i] + 32;
			i++;
		}
		str = temp;
		return (str);
	}
	return (NULL);
}

void content_change(struct node_list *node, void (*f)(void *))
{
	struct node_list	*temp;
	
	if (node)
	{
		temp = node;
		while(temp != NULL)
		{
			if (temp->content)
				do_something(temp->content);
			temp = temp->nodes;
		}
	}
}

void	reverse_list(struct	node_list	**head)
{
	struct node_list	*next;
	struct node_list	*prev;
	struct node_list	*current;

	next = NULL;
	prev = NULL;
	current = *head;
	while (current != NULL)
	{
		next = current->nodes;
		current->nodes = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

struct node_list	*ft_lstmap(struct node_list *lst, void *(*f)(void *), void (*del)(void *))
{
	struct node_list	*new;
	struct node_list	*temp;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		temp = malloc(sizeof(struct node_list));
		if (!temp)
			return (NULL);
		temp->body_int = lst->body_int;
		temp->content = f(lst->content);
		if (!temp->content)
			del(temp->content);
		temp->nodes = NULL;
		if (new == NULL)
			new = temp;
		else
			add_back(&new, temp);
		lst = lst->nodes;
	}
	return (new);
}

int	main(void)
{

	struct node_list	*n1;
	struct node_list	*new_front;
	struct node_list	*new_back;
	struct node_list	*last;
	struct node_list	*deleted;
	struct node_list	*next;
	struct node_list	*n2;
	int					size;

//-------- CREATING FIRST NODE   ---------------------------------------|


	printf("\n\n----- LST_NEW -----\n\n");
	n1 = (struct node_list *)malloc(sizeof(struct node_list));
	n1->body_int = 5;
	n1->content = ft_strdup("whatever");;
	n1->nodes = NULL;
	printf("Node with body '%d' and content '%s' created.\n", n1->body_int, n1->content);

//-------- CREATING THE BACK NODE --------------------------------------|	
	

	printf("\n\n----- ADD_BACK -----\n\n");

	new_back = (struct node_list *)malloc(sizeof(struct node_list));
	new_back->body_int = 6;
	new_back->content = ft_strdup("you want");;
	new_back->nodes = NULL;

	printf("Node with body '%d' and content '%s' created.\n", new_back->body_int, new_back->content);

//-------- APPLYING THE FUNCTION ---------------------------------------|	
	
	add_back(&n1, new_back);

//-------- CREATING THE FRONT NODE -------------------------------------|

	printf("\n\n----- ADD_FRONT -----\n\n");

	new_front = (struct node_list *)malloc(sizeof(struct node_list));
	new_front->body_int = 10;
	new_front->content = ft_strdup("do");
	new_front->nodes = NULL;
	
	printf("Node with body '%d' and content '%s' created.\n", new_front->body_int, new_front->content);


//-------- APPLYING THE FUNCTION ---------------------------------------|	
	
	add_front(&n1, new_front);

//-------- ITERATING THRU THE NODELIST ---------------------------------|

	show_list(n1);	

//-------- SIZE OF THE STRUCT ------------------------------------------|

	printf("\n\n----- LST_SIZE -----\n\n");
	printf("\nThere are %d nodes on your list\n", struct_size(n1));
	

//-------- RETURN LAST NODE --------------------------------------------|


	printf("\n\n----- LST_LAST -----\n\n");
	last = return_last(n1);
	printf("\nLast node is: ");
	show_node(last);

//-------- ITERATING EVERY CONTENT AND CHANGE IT -----------------------|

	printf("\n\n----- LST_ITERI -----\n\n");
	content_change(n1, do_something);
	show_list(n1);
	printf("\n");
	//printf("reverse:\n");
	//reverse_list(&n1);
	//show_list(n1);
	//reverse_list(&n1);

//-------- CREATE A NEW HEAD -------------------------------------------|
	
	printf("\n\n----- LST_MAPI -----\n\n");
	n2 = ft_lstmap(n1, do_some, free_content);
	printf("after creating\n");
	show_list(n2);
		
//-------- DELETE A NODE -----------------------------------------------|

	printf("\n\n----- LST_DELONE -----\n\n");
	
	deleted = return_node(n1, 2);
	printf("Deleted  node is: ");
	show_node(deleted);
	skip_node(&n1, deleted);
	del_node(deleted, free_content);

//-------- FLUSHING THE LIST -------------------------------------------|

	printf("\n\n----- LST_CLEAR -----\n\n");

	show_list(n1);	
	printf("\nTrying to flush the list ...\n");
	struct_clear(&n1, free_content);
	printf("\nSuccessfully!\n");
	printf("Printing the resulted list\n");
	show_list(n1);
	printf("After trying to print the list\n");

//-------- FLUSHING THE LIST -------------------------------------------|

}