/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inserion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:32:18 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/16 10:22:55 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_insertion(t_stack *lst)
{
	int	*arr;
	int	tmp;
	int	i;
	int	j;

	arr = ft_clone_stack(lst);
	i = 1;
	while (i < ft_lstsize_ps(lst))
	{
		tmp = arr[i];
		j = i - 1;
		while (tmp < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
	return (arr);
}
