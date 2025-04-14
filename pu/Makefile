CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

SRC = main.c	parsing.c	split.c	stack_utils.c	utils.c	\
rotations.c	push.c	reverse_rotations.c	sorting.c	swap.c	\
sorting_tools.c	stack_init_a.c	stack_init_b.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)	$(FLAGS)	$(OBJ)	-o	$(NAME)

%.o : %.c	push_swap.h
	$(CC)	$(FLAGS)	-c	$<	-o	$@

clean :
	$(RM)	$(OBJ)

fclean : clean
	$(RM)	$(NAME)	$(LIBFT)

re : fclean	all


