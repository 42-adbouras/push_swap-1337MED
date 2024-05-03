/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:20:05 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/27 15:32:01 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_ps(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_stack	*ft_lstnew_ps(int n)
{
	t_stack		*node;
	static int	index; 

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = n;
	node->index = index;
	index++;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast_ps(*lst);
	node->next = new;
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *lst;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*lst = NULL;
}
