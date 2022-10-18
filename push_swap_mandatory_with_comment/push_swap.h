/*
python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

//
chmod 777 checker_Mac
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
//

gcc push_swap.c fatoi.c ./libft/ft_split.c ./libft/ft_strlen.c ./libft/ft_lstsize.c ./libft/ft_lstadd_back.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c transfer.c utils.c stack_operation.c ./libft/ft_lstadd_front.c action.c final_action.c

gcc -fsanitize=address -g push_swap.c fatoi.c ./libft/ft_split.c ./libft/ft_strlen.c ./libft/ft_lstsize.c ./libft/ft_lstadd_back.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c transfer.c utils.c stack_operation.c ./libft/ft_lstadd_front.c action.c final_action.c

*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // потом убрать

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_num
{
	int flag;	// для main, ситуативный флаг

	int mean;	// медиана
	int min;	// минимум
	int max;	// максимум
	
	int length; // длина ситуативная, для проверки 

	int a;		  // ситуативный флаг
	int move_min; // сколько движений нужно минимум для переброса

	int length_a; // сколько сейчас в стеке а
	int length_b; // сколько сейчас в стеке б
	int last_a_rank;

	int code_1;
	int code_2;

	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}	t_num;

int 	checker(char *argv);
int		fatoi(const char *str, t_num *check);
void	free_stack(t_list **head);

void transfer_a_to_b(t_list **lst, t_num *check);
void pre_sorting(t_list **stack_a, t_list **stack_b, t_num *check);
void final_sort(t_list **stack_a, t_num *check);

// Операции
t_list *stack_r(t_list **lst);
t_list *stack_rr(t_list **lst);
t_list *stack_s(t_list **lst);
void	stack_p(t_list **head_from, t_list **head_to);

// Временно, потом удалить
void   ft_print(t_list *lst);
void  ft_print_rank(t_list *lst);

#endif
