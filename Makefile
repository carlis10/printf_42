# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:56:54 by Carlos            #+#    #+#              #
#    Updated: 2023/12/13 14:18:00 by cravegli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= libftprintf.a
INCLUDE			= include/ft_printf.h
LIBFT			= libft
SRC_DIR			= src/
SRC_DIR_BONUS	= src_bonus/
OBJ_DIR			= obj/
OBJ_DIR_BONUS	= obj_bonus/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -rf
AR				= ar rcs


SRC			= ft_printf.c ft_printf_utils.c ft_printf_aux.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus:
			@make -C $(SRC_DIR_BONUS)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)


clean:
			@$(RM) $(OBJ_DIR)
			@$(RM) $(OBJ_DIR_BONUS)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean $(OBJ_DIR) all

.PHONY:		all clean fclean re
