/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:45:22 by aghergut          #+#    #+#             */
/*   Updated: 2024/03/04 17:23:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_list(t_list	**head)
{
	t_list	*nxt;
	t_list	*prev;
	t_list	*current;

	if (*head != NULL && head != NULL)
	{
		nxt = NULL;
		prev = NULL;
		current = *head;
		while (current != NULL)
		{
			nxt = current->next;
			current->next = prev;
			prev = current;
			current = nxt;
		}
		*head = prev;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (ft_lstsize(*lst) > 0)
		{
			reverse_list(lst);
			ft_lstadd_front(lst, new);
			reverse_list(lst);
		}
		else
			*lst = new;
	}
	else
		*lst = new;
}
