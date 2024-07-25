# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 09:56:48 by dde-carv          #+#    #+#              #
#    Updated: 2024/07/24 12:58:31 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	./libft/libft.a
INC	=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

CC	=	@gcc
CFLAGS	=	-Wall -Werror -Wextra -g -I
RM	=	@rm -f

COMMANDS_DIR	=	$(SRC_DIR)commands/push.c \
			$(SRC_DIR)commands/rev_rotate.c \
			$(SRC_DIR)commands/rotate.c \
			$(SRC_DIR)commands/sort_s.c \
			$(SRC_DIR)commands/sort_three.c \
			$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR	=	$(SRC_DIR)push_swap_u/errors.c \
			$(SRC_DIR)push_swap_u/init_ab.c \
			$(SRC_DIR)push_swap_u/init_ba.c \
			$(SRC_DIR)push_swap_u/init_s.c \
			$(SRC_DIR)push_swap_u/main.c \
			$(SRC_DIR)push_swap_u/utils_s.c

SRCS	=	$(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(LIBFT):
		@make -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

clean:
		$(RM) -r $(OBJ_DIR)
		@make clean -C ./libft

fclean:		clean
		$(RM) $(NAME)
		@make fclean -C ./libft

re:		fclean all

.PHONY:		all clean fclean re