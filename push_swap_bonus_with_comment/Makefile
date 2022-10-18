SRCS = push_swap.c transfer.c \
	   action.c final_action.c \
	   stack_operation.c \
	   parser.c fatoi.c checker.c error.c free.c \
	   utils.c 

BSRCS = bonus_main.c bonus_read_ins.c stack_operation.c \
		parser.c fatoi.c checker.c error.c free.c \
		utils.c 

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = 	push_swap
BNAME = checker

CC = 	gcc
CFLAGS = -Wall -Wextra -Werror  
# -fsanitize=address -g
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

#
clean:
	${RM} ${OBJS}
	${RM} ${BOBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BNAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BSRCS}
	norminette -R CheckDefine ${HDRS}

.PHONY: all clean fclean re bonus norm
