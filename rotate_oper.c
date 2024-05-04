/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:10:01 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:24:04 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*first;

	if (ft_lstsize_ps(*lst) < 2)
		return ;
	last = ft_lstlast_ps(*lst);
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_stack **lst)
{
	if (ft_lstsize_ps(*lst) < 2)
		return ;
	ft_rotate(lst);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **lst)
{
	if (ft_lstsize_ps(*lst) < 2)
		return ;
	ft_rotate(lst);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (ft_lstsize_ps(*a) < 2 || ft_lstsize_ps(*a) < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
