# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 13:27:42 by yyatsenk          #+#    #+#              #
#    Updated: 2017/11/15 16:20:04 by yyatsenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
RM = rm -rf
CCFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB = -C $(D_LIB)
OBJS = $(SRCS:.c=.o)
D_SRCS = ./srcs/
D_LIB = ./libft/
D_INC = ./srcs/fdf.h
SRCS = main.c \
	   draw.c \
	   file_read_and_fill.c \
	   line_together.c \
	   set_var_reload.c \
	   something_with_memory.c
SUCCES_COLOR = \033[32m
.PHONY: all clean fclean re

all: $(NAME)

%.o:$(D_SRCS)%.c
		@$(CC) -g $(CCFLAGS) -I $(D_LIB) -I $(D_INC) -o $@ -c $<

$(NAME): $(OBJS)
		@make $(LIB)
		@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) -L $(D_LIB) -lft $(MLXFLAGS)
		@echo "$(SUCCES_COLOR)$(NAME) - DONE :)"

clean:
		@make clean $(LIB)
		@echo "$(SUCCES_COLOR)$(NAME) - Object file cleaned :)"
		@$(RM) $(OBJS)

fclean: clean
		@make fclean $(LIB)
		@$(RM) $(NAME)
		@echo "$(SUCCES_COLOR)$(NAME) - Executable cleaned :)"

re: fclean all
