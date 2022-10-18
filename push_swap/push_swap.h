/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:40:25 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 22:29:31 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_num
{
	int		flag;

	int		mean;
	int		min;
	int		max;

	int		length;

	int		a;
	int		move_min;

	int		length_a;
	int		length_b;
	int		last_a_rank;

	int		code_1;
	int		code_2;

	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_num;

// Parser
int		perebor(char **a, t_list **stack_a, t_num *check);

// Cheack
int		fatoi(const char *str, t_num *check);
int		stek_cheack(t_list **lst, t_num *check);

// Transfer
t_list	**find_trio(t_list **lst, t_num *check);
void	ranks_dis(int *num, t_list **lst, t_num *check);
void	bubblesort(int *num, int size);
t_list	*a_sort(t_list **lst);

// Free
void	mem_free(char *a);
void	free_stack(t_list **head);

// Errors
int		stek_cheack_error(void);
int		flag_error(char **a, t_list *stack_a, int l);
int		empty_error(char **a, t_list *stack_a, int l);

// Sort mandatory
void	transfer_a_to_b(t_list **lst, t_num *check);
void	pre_sorting(t_list **stack_a, t_list **stack_b, t_num *check);
void	move_score(t_list *stack_a, t_list *stack_b, t_num *check);
void	save_move(t_list *current_a, t_list *current_b, t_num *check);
void	realize(t_list **stack_a, t_list **stack_b, t_num *check);
void	final_sort(t_list **stack_a, t_num *check);

// Stack operation
t_list	*first_b(t_list **lst);
t_list	*stack_r(t_list **lst);
t_list	*stack_rr(t_list **lst);
t_list	*stack_s(t_list **lst);
void	stack_p(t_list **head_from, t_list **head_to);

// Bonus
void	read_instructions(t_list **stack_a);
int		stek_cheack_bonus(t_list **lst, t_num *check);
int		do_comand(t_list **stack_a, t_list **stack_b, char *comand);

#endif
