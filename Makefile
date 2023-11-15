# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:56:54 by Carlos            #+#    #+#              #
#    Updated: 2023/11/06 12:58:16 by Carlos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf_aux.c printf_utils.c ft_printf.c ft_putnbr_base.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS) -c $(SRC)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

RM = rm -f

$(NAME):
	@$(CC)
	@$(LIB) $(OBJ)
	@$(RANLIB)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
