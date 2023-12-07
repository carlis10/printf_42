# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:36:17 by cravegli          #+#    #+#              #
#    Updated: 2023/12/07 13:50:59 by cravegli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ../libftprintf.a
INCLUDE			= include
SRC_DIR_BONUS	= .
OBJ_DIR_BONUS	= ../obj_bonus/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -rf
AR				= ar rcs


SRC_BONUS	= ft_add_size_bonus.c ft_printf_bonus.c ft_printf_extra_bonus.c \
			ft_printf_num_bonus.c ft_printf_unnum_bonus.c ft_printf_aux_bonus.c \
			ft_printf_utils_bonus.c

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(SRC_BONUS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ_BONUS)
			@$(AR) $(NAME) $(OBJ_BONUS)

$(OBJ_BONUS): $(SRC_BONUS) | $(OBJ_DIR_BONUS)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR_BONUS):
			@mkdir -p $(OBJ_DIR_BONUS)

clean:
			@$(RM) $(OBJ_DIR_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(OBJ_DIR_BONUS) all

.PHONY:		all clean fclean re