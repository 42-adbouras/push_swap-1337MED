/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:23:52 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/30 11:46:13 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	if (ac == 1)
		return (1);
	while (av[++i])
		ft_stack_init(&a, av[i]);
	if (!if_sorted(a))
	{
		if (ft_lstsize_ps(a) <= 3)
			ft_sort_three(&a);
		else if (ft_lstsize_ps(a) <= 5)
			ft_sort_five(&a, &b);
		else if (ft_lstsize_ps(a) <= 100)
			ft_big_sort(&a, &b, 13);
		else
			ft_big_sort(&a, &b, 37);
	}
	ft_lstclear_ps(&a);
	return (0);
}
