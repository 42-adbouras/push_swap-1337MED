/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:25:55 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:24:01 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **lst)
{
	t_stack	*last; 
	t_stack	*prev;

	if (ft_lstsize_ps(*lst) < 2)
		return ;
	last = *lst;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	ft_rra(t_stack **lst)
{
	if (ft_lstsize_ps(*lst) < 2)
		return ;
	ft_rev_rotate(lst);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **lst)
{
	if (ft_lstsize_ps(*lst) < 2)
		return ;
	ft_rev_rotate(lst);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (ft_lstsize_ps(*a) < 2 || ft_lstsize_ps(*a) < 2)
		return ;
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
