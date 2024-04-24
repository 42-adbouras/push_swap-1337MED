/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:08:18 by adbouras          #+#    #+#             */
/*   Updated: 2024/04/24 16:20:41 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./bonus/get_next_line/get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct stack_list
{
	int					value;
	int					index;
	int					pose;
	struct stack_list	*next;
}						t_stack;

t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack	*ft_lstnew_ps(int n);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void	ft_stack_init(t_stack **lst, char *arg);
int		*ft_clone_stack(t_stack *lst);
int		ft_lstsize_ps(t_stack *lst);

t_stack	*ft_find_min(t_stack *lst);
t_stack	*ft_find_max(t_stack *lst);
void	ft_big_sort(t_stack **lst_a, t_stack **lst_b, int range);
void	ft_migrate_b(t_stack **lst_a, t_stack **lst_b);
void	ft_sort_five(t_stack **lst_a, t_stack **lst_b);
void	ft_sort_three(t_stack **lst);
void	ft_set_pose(t_stack *lst);
void	ft_re_index(t_stack *lst);
void	ft_check(t_stack *lst);
bool	if_sorted(t_stack *lst);

int		*ft_insertion(t_stack *lst);

void	ft_lstclear_ps(t_stack **lst);
void	free_char(char **arr);
void	exit_err(void);

void	ft_push(t_stack **lst, t_stack **new);
void	ft_push_a(t_stack **lst, t_stack **new);
void	ft_push_b(t_stack **lst, t_stack **new);

void	ft_swap(t_stack *lst);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

void	ft_rotate(t_stack **lst);
void	ft_ra(t_stack **lst);
void	ft_rb(t_stack **lst);
void	ft_rr(t_stack **a, t_stack **b);

void	ft_rev_rotate(t_stack **lst);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
