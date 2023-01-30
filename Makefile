NAME = push_swap

SRC = push_swap_utils.c sort_the_list.c smaller_list.c indexing.c check.c \
		push_swap_utils_2.c sort_the_list2.c errors.c read_numbers.c read_numbers_utils.c main.c

SRC_BONUS = push_swap_utils.c sort_the_list.c smaller_list.c indexing.c check.c \
		push_swap_utils_2.c sort_the_list2.c errors.c read_numbers.c read_numbers_utils.c checker.c
CC = gcc

CFLAGS = -Wall -Wextra -Werror 
LIBPRINT = ./printf/libftprintf.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ) $(LIBPRINT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBPRINT) -o $(NAME)

all: $(NAME)

$(LIBPRINT):
		make -C ./printf

bonus: $(OBJ_BONUS)
	make -C ./printf
	$(CC) $(CFLAGS) $(SRC_BONUS) ./printf/libftprintf.a ./gnl/get_next_line.c ./gnl/get_next_line_utils.c -o checker

clean:
	rm -rf $(OBJ)
	rm -rf checker
	rm -rf main.o
	make -C ./printf clean

fclean: clean
	rm -rf $(OBJ) $(NAME) $(OBJ_BONUS)
	make -C ./printf fclean

re: fclean all

.PHONY: all re clean fclean 
