# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:45:23 by schaaban          #+#    #+#              #
#    Updated: 2018/02/14 16:10:33 by schaaban         ###   ########.fr        #
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

MLIB_DIR	=		./minilibx
MLIB_I_DIR	=		$(MLIB_DIR)
MLIB_NAME	=		mlx

CC_INC		=		-I$(INC_DIR) -I$(LFT_I_DIR) -I$(MLIB_I_DIR)
CC_LINK		=		-L$(LFT_DIR) -l$(LFT_NAME) -L$(MLIB_DIR) -l$(MLIB_NAME) -lm
CC_MLIB		=		-lXext -lX11

SRCS		=		$(addprefix $(SRCS_DIR)/, 	\
					main.c						\
					parser.c					\
					init.c						\
					exit.c						\
					key_handler.c				\
					drawer.c					\
					graphics.c					\
					ui.c						\
					tools.c						\
					draw_map.c					)
OBJS		=		$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): dir_creation $(OBJS)
	@$(MAKE) -C $(LFT_DIR)
	@$(MAKE) -C $(MLIB_DIR)
	@$(CC) $(FLAGS) $(OBJS) $(CC_INC) $(CC_LINK) $(CC_MLIB) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC_DIR)/$(NAME).h
	@$(CC) $(FLAGS) $(CC_INC) -o $@ -c $<

dir_creation:
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LFT_DIR) clean
	@$(MAKE) -C $(MLIB_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LFT_DIR) fclean
	@$(MAKE) -C $(MLIB_DIR) clean

re: fclean all

.PHONY: all re clean fclean dir_creation
