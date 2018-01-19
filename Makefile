# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:45:23 by schaaban          #+#    #+#              #
#    Updated: 2018/01/18 09:04:29 by schaaban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fdf

CC			=		gcc
FLAGS		=		-Wall -Werror -Wextra

INC_DIR		=		./includes
SRCS_DIR	=		./srcs
OBJS_DIR	=		./objs

LFT_DIR		=		./libft
LFT_I_DIR	=		$(LFT_DIR)/includes
LFT_NAME	=		ft

MLIB_DIR	=		./minilibx_macos
MLIB_I_DIR	=		$(MLIB_DIR)
MLIB_NAME	=		mlx

CC_INC		=		-I$(INC_DIR) -I$(LFT_I_DIR) -I$(MLIB_I_DIR)
CC_LINK		=		-L$(LFT_DIR) -l$(LFT_NAME) -L$(MLIB_DIR) -l$(MLIB_NAME)
CC_MLIB		=		-framework OpenGL -framework AppKit

SRCS		=		$(addprefix $(SRCS_DIR)/, 	\
					main.c						\
					parser.c)
OBJS		=		$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): dir_creation $(OBJS)
	@$(MAKE) -C $(LFT_DIR)
	@$(MAKE) -C $(MLIB_DIR)
	@$(CC) $(FLAGS) $(CC_LINK) $(CC_MLIB) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(FLAGS) $(CC_INC) -o $@ -c $<

dir_creation:
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LFT_DIR) clean
	@$(MAKE) -C $(MLIB_DIR) clean

fclean:
	@rm -rf $(NAME)
	@$(MAKE) -C $(LFT_DIR) fclean
	@$(MAKE) -C $(MLIB_DIR) clean

re: fclean all

.PHONY: all re clean fclean dir_creation
