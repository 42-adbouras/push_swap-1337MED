/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_opera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:36:15 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/22 15:14:32 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exit_err(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
