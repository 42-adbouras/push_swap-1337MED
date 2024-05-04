/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:58:03 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:23:08 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

void	ft_verify(int c)
{
	if (ft_isdigit(c) == 0)
		exit_err();
}

long	ft_proc(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		exit_err();
	return (result);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0')
			exit_err();
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		ft_verify(str[i]);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (ft_proc(result));
}
