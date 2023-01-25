# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:45:31 by msaydam           #+#    #+#              #
#    Updated: 2023/01/25 13:07:13 by msaydam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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