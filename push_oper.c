/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:29:43 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/24 16:15:08 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **lst, t_stack **new)
{
	t_stack	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = *new;
	*new = tmp;
}

void	ft_push_a(t_stack **lst, t_stack **new)
{
	if (*lst == NULL)
		return ;
	ft_push(lst, new);
	ft_printf("pa\n");
}

void	ft_push_b(t_stack **lst, t_stack **new)
{
	if (*lst == NULL)
		return ;
	ft_push(lst, new);
	ft_printf("pb\n");
}
