/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:57:35 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/24 16:15:58 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *lst)
{
	if (ft_lstsize_ps(lst) < 2)
		return ;
	lst->value ^= lst->next->value;
	lst->next->value ^= lst->value;
	lst->value ^= lst->next->value;
}

void	ft_sa(t_stack *lst)
{
	if (ft_lstsize_ps(lst) < 2)
		return ;
	ft_swap(lst);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *lst)
{
	if (ft_lstsize_ps(lst) < 2)
		return ;
	ft_swap(lst);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (ft_lstsize_ps(a) < 2 || ft_lstsize_ps(b) < 2)
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
