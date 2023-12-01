# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:56:54 by Carlos            #+#    #+#              #
#    Updated: 2023/12/01 13:53:18 by Carlos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= libftprintf.a
INCLUDE			= include
LIBFT			= libft
SRC_DIR			= src/
SRC_DIR_BONUS	= src_bonus/
OBJ_DIR			= obj/
OBJ_DIR_BONUS	= obj_bonus/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -f
AR				= ar rcs


SRC			= ft_printf.c ft_printf_utils.c ft_printf_aux.c

SRC_BONUS	= ft_add_size_bonus.c ft_printf_bonus.c ft_printf_extra_bonus.c \
			ft_printf_num_bonus.c ft_printf_unnum_bonus.c ft_printf_aux_bonus.c \
			ft_printf_utils_bonus.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(SRC_BONUS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus:		$(OBJ_BONUS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ_BONUS)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
			@mkdir -p $(OBJ_DIR_BONUS)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(OBJ_DIR_BONUS)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
