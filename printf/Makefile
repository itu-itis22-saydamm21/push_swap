SRC		= ft_printf.c

OBJ		= $(SRC:.c=.o)

NAME	= libftprintf.a

CC		= @gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= @rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)