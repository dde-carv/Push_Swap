# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 09:56:48 by dde-carv          #+#    #+#              #
#    Updated: 2024/08/02 16:19:49 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker

LIBFT	=	./libft/libft.a
INC	=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/
SRCB_DIR	=	src_b/
OBJB_DIR	=	obj_b/

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
			$(SRC_DIR)push_swap_u/main_ps.c \
			$(SRC_DIR)push_swap_u/utils_s.c

BONUS_DIR	=	$(SRCB_DIR)checker_u/main_ch.c

SRCS	=	$(COMMANDS_DIR) $(PUSH_SWAP_DIR)
SRCS_B	=	$(BONUS_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_B	=	$(patsubst $(SRCB_DIR)%/*.c,$(OBJB_DIR)%/*.o,$(SRCS_B))

$(LIBFT):
		@make -s -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
		@echo "Make .o and push_swap."
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_B):	$(OBJS) $(LIBFT)
		@echo "Make .o, push_swap and checker."
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)
		@$(CC) $(CFLAGS) $(INC) $(OBJS_B) $(LIBFT) -o $(NAME_B)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

bonus:		$(NAME_B)

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		all bonus clean fclean re