# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeojang <hyeojang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 22:38:16 by hyeojang          #+#    #+#              #
#    Updated: 2021/05/19 23:53:17 by hyeojang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -o3
# CFLAGS		= -g3 -fsanitize=address

ifeq ($(DEBUG),true)
	CFLAGS += -g
endif

RM			= rm -rf
INCLS		= ./includes/.
LMLX		= libmlx.dylib

OBJS		= $(SRCS:.c=.o)
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_DIR	= ./srcs/
SRCS_LIST	= main.c exit.c event.c save.c render.c move.c render_utils.c\
				render_sprite.c \
				utils/get_next_line_utils.c utils/get_next_line.c \
				utils/ft_strcmp.c utils/ft_memset.c utils/ft_split.c \
				utils/free_word.c utils/ft_memmove.c utils/ft_lstadd_back.c \
				utils/ft_lstclear.c utils/ft_lstnew.c utils/ft_lstsize.c \
				utils/ft_lstlast.c utils/put_xy.c \
				inits/init_map.c inits/init.c inits/init_parse.c \
				inits/init_texture.c inits/init_resolution.c \
				inits/init_color.c

all: $(NAME)

$(LMLX) :
	@$(MAKE) -C mlx
	@cp mlx/libmlx.dylib .

$(NAME) : $(LMLX) $(OBJS)
	@$(CC) $(CFLAGS) -I $(INCLS) $(LMLX) $(OBJS) -o $(NAME)

clean:
	@$(MAKE) -C mlx clean
	$(RM) $(OBJS)
	$(RM) image.bmp

fclean: clean
	$(RM) $(NAME) $(LMLX)

re: fclean all
