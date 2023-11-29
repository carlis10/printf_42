# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:56:54 by Carlos            #+#    #+#              #
#    Updated: 2023/11/29 16:19:20 by cravegli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf_aux.c printf_utils.c ft_printf.c ft_putnbr_base.c

OBJ = ${SRC:.c=.o}

BONUS = ft_printf_bonus.c printf_utils_bonus.c printf_aux_bonus.c \
		ft_printf_extra_bonus.c ft_add_size_bonus.c ft_printf_num_bonus.c \
		ft_printf_unnum_bonus.c

BONUS_OBJ = ${BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

RM = rm -f

$(NAME):
	@$(CC) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)

bonus:
	@$(CC) $(BONUS)
	@$(LIB) $(BONUS_OBJ)
	@$(RANLIB)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
