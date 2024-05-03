/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:08:09 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/27 15:25:06 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **lst)
{
	if (ft_lstsize_ps(*lst) == 2)
	{
		if ((*lst)->value > ((*lst)->next->value))
			ft_sa(*lst);
		return ;
	}
	if ((*lst)->value > (*lst)->next->value
		&& (*lst)->value > (*lst)->next->next->value)
		ft_ra(lst);
	else if ((*lst)->next->value > (*lst)->value
		&& (*lst)->next->value > (*lst)->next->next->value)
		ft_rra(lst);
	if ((*lst)->value > (*lst)->next->value)
		ft_sa(*lst);
}

void	ft_sort_five(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*min;

	min = ft_find_min(*lst_a);
	while ((*lst_a)->value != min->value)
	{
		if (min->index <= 2)
			ft_ra(lst_a);
		else
			ft_rra(lst_a);
	}
	ft_push_b(lst_a, lst_b);
	min = ft_find_min(*lst_a);
	ft_re_index(*lst_a);
	while ((*lst_a)->value != min->value)
	{
		if (min->index < 2)
			ft_ra(lst_a);
		else
			ft_rra(lst_a);
	}
	ft_push_b(lst_a, lst_b);
	ft_sort_three(lst_a);
	ft_migrate_b(lst_a, lst_b);
}

void	ft_big_sort(t_stack **lst_a, t_stack **lst_b, int range)
{
	int		start;
	int		end;

	start = 0;
	ft_set_pose(*lst_a);
	while (*lst_a != NULL)
	{
		end = start + range;
		if ((*lst_a)->pose >= start && (*lst_a)->pose <= end)
		{
			ft_push_b(lst_a, lst_b);
			start++;
		}
		else if ((*lst_a)->pose < start)
		{
			ft_push_b(lst_a, lst_b);
			ft_rb(lst_b);
			start++;
		}
		else
			ft_ra(lst_a);
	}
	ft_migrate_b(lst_a, lst_b);
}

void	ft_stack_init(t_stack **lst, char *arg)
{
	int		i;
	char	**arr;
	t_stack	*new;

	i = 0;
	arr = ft_split(arg, ' ');
	while (arr[i])
	{
		new = ft_lstnew_ps(ft_atoi(arr[i]));
		if (new == NULL)
		{
			ft_lstclear_ps(lst);
			return (free_char(arr));
		}
		ft_lstadd_back_ps(lst, new);
		i++;
	}
	free_char(arr);
	ft_check(*lst);
}
