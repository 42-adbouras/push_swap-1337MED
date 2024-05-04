/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:37:04 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/04 12:22:47 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	ft_check_move(char *move);
void	ft_move_exe(char *move, t_stack **a, t_stack **b);
void	ft_print_output(t_stack *a, t_stack *b);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*move;

	if (ac == 1)
		return (0);
	i = 1;
	while (av[i])
		ft_stack_init(&a, av[i++]);
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		if (!ft_check_move(move))
			exit_err();
		ft_move_exe(move, &a, &b);
		free(move);
	}
	ft_print_output(a, b);
	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
	return (0);
}

void	ft_print_output(t_stack *a, t_stack *b)
{
	if (if_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

bool	ft_check_move(char *move)
{
	if (!ft_strncmp(move, "sa\n", 3) || !ft_strncmp(move, "sb\n", 3)
		|| !ft_strncmp(move, "ss\n", 3) || !ft_strncmp(move, "pa\n", 3)
		|| !ft_strncmp(move, "pb\n", 3) || !ft_strncmp(move, "ra\n", 3)
		|| !ft_strncmp(move, "rb\n", 3) || !ft_strncmp(move, "rr\n", 3)
		|| !ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move, "rrb\n", 4)
		|| !ft_strncmp(move, "rrr\n", 4))
		return (true);
	return (false);
}

void	ft_move_exe(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(move, "sa\n", 3) || !ft_strncmp(move, "ss\n", 3))
		ft_swap(*a);
	if (!ft_strncmp(move, "sb\n", 3) || !ft_strncmp(move, "ss\n", 3))
		ft_swap(*b);
	if (!ft_strncmp(move, "pa\n", 3))
		ft_push(b, a);
	if (!ft_strncmp(move, "pb\n", 3))
		ft_push(a, b);
	if (!ft_strncmp(move, "ra\n", 3) || !ft_strncmp(move, "rr\n", 3))
		ft_rotate(a);
	if (!ft_strncmp(move, "rb\n", 3) || !ft_strncmp(move, "rr\n", 3))
		ft_rotate(b);
	if (!ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move, "rrr\n", 4))
		ft_rev_rotate(a);
	if (!ft_strncmp(move, "rrb\n", 4) || !ft_strncmp(move, "rrr\n", 4))
		ft_rev_rotate(b);
}
