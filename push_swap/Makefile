SRCS = push_swap.c transfer.c transfer_two.c \
	   action.c action_two.c action_three.c final_action.c \
	   stack_operation.c \
	   parser.c fatoi.c checker.c error.c free.c \

BSRCS = bonus_main.c bonus_read_ins.c \
		do_comand.c stack_operation.c \
		parser.c fatoi.c checker.c error.c free.c \

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = 	push_swap
BNAME = checker

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f
LIB_FT = libft/libft.a

all:	$(NAME)

$(MOBJS):$(HDRS) Makefile
$(OBJS):$(HDRS) Makefile
$(BOBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FT) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(BOBJS) $(LIB_FT) -o $(BNAME)

clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}
	make fclean -C ./libft

re: fclean all bonus

.PHONY: all clean fclean re bonus norm
