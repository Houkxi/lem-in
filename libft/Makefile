# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:58:31 by mmanley           #+#    #+#              #
#    Updated: 2018/05/17 20:41:45 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = includes/

PRINTF = libftprintf.a

OBJ_PATH = objs/

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

include nbrs/make.dep
include mems/make.dep
include lst_ch/make.dep
include srcs/make.dep
include strs/make.dep
include put/make.dep

OBJS_NAME =	$(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_NAME))

all : $(PRINTF) $(NAME)

$(NAME) : objs $(OBJS) info
	@cp ft_printf/libftprintf.a ./libft.a
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(PRINTF) :
	@make -C ft_printf

$(OBJ_PATH)%.o: %.c
	@./dot.sh .
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

info :
	@echo "${GREEN}\033[A\033[J${WHITE}"
	@echo "${WHITE}libft.a${GREEN}			DONE${WHITE}"

objs:
	@mkdir -p objs
	@mkdir -p objs/mems
	@mkdir -p objs/nbrs
	@mkdir -p objs/lst_ch
	@mkdir -p objs/strs
	@mkdir -p objs/srcs
	@mkdir -p objs/put

clean :
	@cd ft_printf && $(MAKE) clean && cd ..
	@rm -rf objs
	@rm -rf $(OBJS_PATH)
	@echo "${WHITE}Libft objs :${RED}		DEL${GREEN}"

fclean : clean
	@cd ft_printf && $(MAKE) fclean && cd ..
	@rm -rf $(NAME)
	@echo "${WHITE}Libft libs :${RED}		DEL${GREEN}"

re : fclean all
