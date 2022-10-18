/*
python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

//
chmod 777 checker_Mac
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
//

gcc push_swap.c fatoi.c ./libft/ft_split.c ./libft/ft_strlen.c ./libft/ft_lstsize.c ./libft/ft_lstadd_back.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c transfer.c utils.c stack_operation.c ./libft/ft_lstadd_front.c action.c final_action.c

gcc -fsanitize=address -g push_swap.c fatoi.c ./libft/ft_split.c ./libft/ft_strlen.c ./libft/ft_lstsize.c ./libft/ft_lstadd_back.c ./libft/ft_lstnew.c ./libft/ft_lstlast.c transfer.c utils.c stack_operation.c ./libft/ft_lstadd_front.c action.c final_action.c

*/

/*
Общие выводы на 18.04. - лучше возврщает указатель на лист, нежели использовать void 
Нельзя обращаться к *, если ** NULL - это автосега
Под б отдельно малочить не надо, главное грамотно передать

Есть какая-то нештатная ситуация с выводом элементов, судя по всему из-за неккоректной передачи - разобраться

1. Ломается алгоритм подсчета
2. Надо учесть что делать, если в стеке б остался последний элемент - чтобы не было rr

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

// Парсер
int		perebor(char **a, t_list **stack_a, t_num *check);

// Проверка
int		fatoi(const char *str, t_num *check);
int		stek_cheack(t_list **lst, t_num *check);
// int 	checker(char *argv); // скорее всего лишняя функция, которую надо будет удалить

// free
void	mem_free(char *a);
void	free_stack(t_list **head);

// errors
int stek_cheack_error();
int flag_error(char **a, t_list *stack_a, int l);
int empty_error(char **a, t_list *stack_a, int l);

// Сортинг мандатори
void transfer_a_to_b(t_list **lst, t_num *check);
void pre_sorting(t_list **stack_a, t_list **stack_b, t_num *check);
void final_sort(t_list **stack_a, t_num *check);

// Операции
t_list *first_b(t_list **lst);
t_list *stack_r(t_list **lst);
t_list *stack_rr(t_list **lst);
t_list *stack_s(t_list **lst);
void	stack_p(t_list **head_from, t_list **head_to);

// Временно, потом удалить
void	ft_print(t_list *lst);
void	ft_print_rank(t_list *lst);
void	ft_print_2(t_list *lst);
void	ft_print_3(t_list **lst);

// bonus
void    read_instructions(t_list **stack_a);
int		stek_cheack_bonus(t_list **lst, t_num *check);

#endif
