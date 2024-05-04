/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:36:40 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:24:11 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_pose(t_stack *lst)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	arr = ft_insertion(lst);
	tmp = lst;
	while (tmp != NULL)
	{
		i = 0;
		while (i < ft_lstsize_ps(lst))
		{
			if (arr[i] == tmp->value)
			{
				tmp->pose = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

bool	if_sorted(t_stack *lst)
{
	t_stack	*head;

	if (!lst)
		return (false);
	head = lst;
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

void	ft_migrate_b(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*max;

	if (!*lst_b)
		return ;
	while ((*lst_b) != NULL)
	{
		max = ft_find_max(*lst_b);
		while ((*lst_b)->value != max->value)
		{
			ft_re_index(*lst_b);
			if (max->index < (ft_lstsize_ps(*lst_b) / 2))
				ft_rb(lst_b);
			else
				ft_rrb(lst_b);
		}
		ft_push_a(lst_b, lst_a);
	}
}
