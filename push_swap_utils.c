/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:20:05 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:23:42 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = lst;
	min = tmp;
	while (tmp != NULL)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_find_max(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = lst;
	max = tmp;
	while (tmp != NULL)
	{
		if (max->value < tmp->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_check(t_stack *lst)
{
	t_stack	*head;
	t_stack	*current;

	current = lst;
	while (current != NULL)
	{
		head = current->next;
		while (head != NULL)
		{
			if (head->value == current->value)
				exit_err();
			head = head->next;
		}
		current = current->next;
	}
}

int	*ft_clone_stack(t_stack *lst)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * ft_lstsize_ps(lst));
	if (!arr)
		return (free(arr), NULL);
	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

void	ft_re_index(t_stack *lst)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}
